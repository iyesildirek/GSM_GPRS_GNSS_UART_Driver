#include <iostream>
#include <stdint.h>

#define OK 0
#define ERROR -1

//Talk
#define START_CALL "ATD"
#define STOP_CALL "ATH"
#define ANSWER_CALL "ATA"

//SMS
#define SET_SMS_TXT_MODE "AT+CMGF=1"
#define SET_SMS_PDU_MODE "AT+CMGF=0"
//Use this is for strings
//#define SMS_GSM "AT+CSCS=\"GSM\""	
#define SMS_GSM "AT+CSCS=GSM"
#define ENABLE_SMS "AT+CSCA=+18178963822"
#define SEND_SMS "AT+CMGS=+18178963822"
#define READ_SMS_1 "AT+CMGR=1"
#define READ_SMS_ALL "AT+CMGL=\"ALL\""
#define DELETE_SMS_1 "AT+CMGD=1"
#define DELETE_SMS_3 "AT+CMGD=3"
#define DELETE_SMS_ALL "AT+CMGD=ALL"

//GPS Default baud rate is 115200
#define POWER_ON_GPS "AT+CGNSPWR=1"
#define POWER_OFF_GPS "AT+CGNSPWR=0"
#define GET_BAUD_GPS "AT+CGNSIPR?"
#define SET_BAUD_GPS "AT+CGNSIPR=numberhere"
#define START_GPS_DATA "AT+CGNSTST=1"
#define STOP_GPS_DATA "AT+CGNSTST=0" 
#define PRINT_GPS_NMEA_DATA "AT+CGNSINF"
#define CHECK_GPS_STATUS "AT+CGPSSTATUS"

//GPRS
#define GET_SIGNAL_QUALITY "AT+CSQ"	//max is 31
#define CHECK_NETWORK_REGISTRY "AT+CREG?"
#define CHECK_GPRS_STATUS "AT+CGATT?"
#define ATTACH_GPRS "AT+CGATT=1"
#define ENABLE_WIRELESS "AT+CIICR"
#define GET_LOCAL_IP "AT+CIFSR"
#define SEND_GPRS_DATA "AT+CIPSEND"
#define CLOSE_GPRS_CONNECTION "AT+CIPCLOSE"
#define SHUTDOWN_GPRS_CONNECTION "AT+CIPSHUT"

//Bluetooth
#define ENABLE_BLUETOOTH "AT+BTPOWER=1"
#define DISABLE_BLUETOOTH "AT+BTPOWER=0"
#define GET_BLUETOOTH_INFO "AT+BTHOST?"
#define SET_BLUETOOTH_NAME "AT+BTHOS=name"
#define SCAN_BLUETOOTH "AT+BTSCAN=1,10"
#define BLUETOOTH_DEVICE "3"
#define PAIR_DEVICE "AT+BTPAIR=0,1" //PAIR TO DEVICE 1
#define CONFIRM_PAIR_DEVICE "AT+BTPAIR=1,1"
#define DELETE_PAIRING "AT+BTUNPAIR=0"
#define CONFIRM_SPP_CONNECTION "AT+BTACPT=1"
#define SEND_BLUETOOTH_DATA "AT+BTSPPSEND"


using namespace std;

class SIM868
{
	public:
	//Constructor
	//SIM868(const SIM868 &);

	//Destructor
	//~SIM868();

	//Class Methods
	int initSIM(void);
	int checkSIM(void);
	int answerCall(void);
	int hangCall(void);
	int phoneCall(string num);	
	int sendSMS(string num);
	int phoneCall(void);	
	int sendSMS(void);
	int readOneSMS(void);	
	int readAllSMS(void);
	
	private:
	
	//Private variables
	string _localNumber;
	
};