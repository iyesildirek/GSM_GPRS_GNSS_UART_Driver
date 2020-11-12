#include <iostream>
#include <string>
#include "../inc/SIM868.h"

using namespace std;

int SIM868::phoneCall(void)
{
	cout << "Call number: " << _localNumber << endl;
	cout << START_CALL << _localNumber << ";"<< endl;
	return OK;
}

int SIM868::phoneCall(string num)
{
	cout << "Call number:" << num << endl;
	cout << START_CALL << num << ";"<< endl;
	return OK;
}

int SIM868::sendSMS(void)
{
	cout << "Text number: " << _localNumber << endl;
	//Send message to number
	cout << SEND_SMS << endl;
	cout << "This is the text message" << endl;
	
	//Wait for response 
	//if response is "+CNGS: 174" then text was sent.
	cout << "Verify we receive +CNGS: 174" << endl;
	return OK;
}

int SIM868::sendSMS(string num)
{
	cout << "Text number: " << num << endl;
	//Send message to number
	cout << "AT+CMGS=+" << num << endl;
	cout << "This is the text message" << endl;
	
	//Wait for response 
	//if response is "+CNGS: 174" then text was sent.
	cout << "Verify we receive +CNGS: 174" << endl;
	return OK;
}

int SIM868::readOneSMS(void)
{
	//Read Message at 1
	cout << "Read Text: " << endl;
	cout << READ_SMS_1 << endl;
	return OK;
}

int SIM868::readAllSMS(void)
{
	//Read all messages
	cout << "Read all cmd: " << READ_SMS_ALL << endl;
	return OK;
}

int SIM868::checkSIM(void)
{
	cout << "Inquiry SIM module" << endl;
	return OK;
}

int SIM868::answerCall(void)
{
	cout << "Answer phone call cmd: ";
	cout << ANSWER_CALL << endl;
	return OK;
}

int SIM868::hangCall(void)
{
	cout << "Hang phone call cmd: ";
	cout << STOP_CALL << endl;
	return OK;
}

int SIM868::initSIM(void)
{
	//Set phone number
	_localNumber = "8178963822";
	
	cout << "Initialize SIM868" << endl;
	
	//Set SMS 
	cout << ENABLE_SMS << endl;
	
	//Set SMS to TEXT mode
	cout << SET_SMS_TXT_MODE << endl;
	
	//Set TE character set
	cout << SMS_GSM << endl;
	
	//Power on GPS
	cout << POWER_OFF_GPS << endl;
	
	//Enable wireless GPRS
	cout << ENABLE_WIRELESS << endl;
	
	//Enable Bluetooth
	cout << ENABLE_BLUETOOTH << endl;
	
	return OK;
}


