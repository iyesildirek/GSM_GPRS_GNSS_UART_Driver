#include <iostream>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include "SIM868.h"

#define NUM_THREADS 1 + 2
#define NUM_CPU_CORES (1)

typedef struct
{
    int threadIdx;
	int sum;
}threadParams_t;

using namespace std;

	struct timeval current_time_val;
    int i, rc, scope;
    cpu_set_t threadcpu;
    pthread_t threads[NUM_THREADS];
    threadParams_t threadParams[NUM_THREADS];
    pthread_attr_t rt_sched_attr[NUM_THREADS];
    int rt_max_prio, rt_min_prio;
    struct sched_param rt_param[NUM_THREADS];
    struct sched_param main_param;
    pthread_attr_t main_attr;
    pid_t mainpid;
    cpu_set_t allcpuset;	
	sem_t semS1;

void initThreads
(
	void
);

void *threadFunc1
(
	void *threadp
);

int main(void)
{
	//Initialize pThreads
	initThreads();	 		 
	
	//SIM868 test code
	cout << endl;
	cout << "Start SIM868" << endl;
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
	return OK;
}

void initThreads()
{
	//Get CPU info
	printf("Initialize threads\n");
	printf("System has %d processors configured and %d available.\n", get_nprocs_conf(), get_nprocs());
	CPU_ZERO(&allcpuset);
	CPU_SET(2, &allcpuset);
	CPU_SET(3, &allcpuset);
	printf("Using CPUS = %d from total available.\n", CPU_COUNT(&allcpuset));

	// Start threads
	int i = 0;	   
	for(i=1; i <=3; i++)
	{
	   /* Initialize remaining struct parameters */
	   threadParams[i].threadIdx=i;
	   
	   pthread_create(&threads[i], // pointer to thread descriptor
                      //(void *)0, // use default attributes
                      NULL,
					  threadFunc1, // thread function entry point
                      (void *)&(threadParams[i]) // parameters to pass in
					  );
	}
   
	for(i=0;i<3;i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	while(pthread_join(threads[1], NULL) != 0 && \
	pthread_join(threads[2], NULL) != 0 && \
	pthread_join(threads[3], NULL) != 0)
	{
	// Wait until all threads are completed
	}
	
	printf("TEST COMPLETE\n");
	
}

void *threadFunc1(void *threadp)
{
    threadParams_t *threadParams = (threadParams_t *)threadp;
	//printf("Thread idx=%d, sum[%d...%d]=%d\n",threadParams->threadIdx);
	printf("Thread idx is: %d\n",threadParams->threadIdx);
	pthread_exit(NULL);
}