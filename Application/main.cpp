/*
*	main.cpp
*
*/

//--------------INCLUDES--------------------------//
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include "SIM868.h"

//--------------DEFINITIONS-----------------------//
#define NUM_THREADS 1 + 1
#define NUM_CPU_CORES (1)

//-----------------STRUCTURES---------------------//
typedef struct
{
    int threadIdx;					///<  Thread ID 
	int sum;						///<  Sum 
}threadParams_t;

//---------GLOBAL VARIABLES-----------------------//   
using namespace std;
pid_t mainpid;								///<  Process ID 
cpu_set_t allcpuset;						///<  CPU Cores 
pthread_t threads[NUM_THREADS];				///<  Threads
threadParams_t threadParams[NUM_THREADS];	///<  Thread parameters
pthread_attr_t main_attr[NUM_THREADS];		///<  Thread attribute
int thread_max_prio;						///<  Thread max priority
int thread_min_prio;						///<  Thread min priority
struct sched_param rt_param[NUM_THREADS];	///<  Thread scheduler parameters

//---------FUNCTION PROTOTYPES-----------------------//   
void initThreads
(
	void
);

void *threadFunc1
(
	void *threadp
);

void *phone
(
	void *threadp
);

//---------FUNCTION DECLARATIONS-----------------------// 
int main(void)
{
	//Initialize pThreads
	initThreads();	 		 

	pthread_exit(NULL);
	return OK;
}

void initThreads(void)
{
	//sem_t mySemaphore;
    //sem_init(&mySemaphore;, 0, 5);
		
	//Get CPU info
	printf("Initialize threads\n");
	printf("System has %d processors configured and %d available.\n", get_nprocs_conf(), get_nprocs());
	CPU_ZERO(&allcpuset);
	CPU_SET(2, &allcpuset);
	CPU_SET(3, &allcpuset);
	printf("Using CPUS = %d from total available.\n", CPU_COUNT(&allcpuset));

	mainpid=getpid();
	//Get Scheduler priority range
    thread_max_prio = sched_get_priority_max(SCHED_FIFO);
    thread_min_prio = sched_get_priority_min(SCHED_FIFO);

	printf("PID: %d, maxprio: %d minprio: %d\n",mainpid,thread_max_prio,thread_min_prio);
	
	
	// Start threads
	int i = 0;	   
	for(i=1; i <= NUM_THREADS; i++)
	{
	   /* Initialize remaining struct parameters */
	   threadParams[i].threadIdx=i;
	   threadParams[i].sum=i;
	}
	
	// Demo pThread
	pthread_create(&threads[1], // pointer to thread descriptor
                  //(void *)0, // use default attributes
                  NULL,
				  threadFunc1, // thread function entry point
                  (void *)&(threadParams[1]) // parameters to pass in
				  );
	
	// SIM868 pThread
	pthread_create(&threads[2], // pointer to thread descriptor
                  //(void *)0, // use default attributes
                  NULL,
				  phone, // thread function entry point
                  (void *)&(threadParams[2]) // parameters to pass in
				  );				  
  
	for(i = 1; i <= NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	//syslog(LOG_CRIT, "All threads for GSM GPRS started!");
	cout << "TEST COMPLETE" << endl;
	//sem_destroy(&mySemaphore;);
}

void *threadFunc1(void *threadp)
{
    threadParams_t *threadParams = (threadParams_t *)threadp;
	cout << "Test Thread idx is: " << threadParams->threadIdx << endl;
	pthread_exit(NULL);
}

void *phone(void *threadp)
{
	
	//SIM868 test code
	cout << "Start SIM868" << endl;
	threadParams_t *threadParams = (threadParams_t *)threadp;
	cout << "SIM868 Thread idx is: " << threadParams->threadIdx << endl;
	SIM868 device1;
	string num1 = "8178963818";
	device1.initSIM();
	device1.checkSIM();	
	device1.sendSMS(num1);
	device1.readOneSMS();
	device1.readAllSMS();
	cout << endl;
	
	device1.phoneCall();
	device1.answerCall();
	device1.hangCall();
	
	pthread_exit(NULL);
}