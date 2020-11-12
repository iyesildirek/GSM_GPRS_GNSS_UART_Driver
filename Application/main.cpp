#include <iostream>
#include "SIM868.h"

using namespace std;

int main(void)
{
	cout << "Hello" << endl;
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
	return OK;
}