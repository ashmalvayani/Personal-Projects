#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include "DeliveryServices.h"
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
 private:
	 char* cus_name;
	 char* email;
	 char* address;
	 char* phone;
	 char* password;
	 char* code;
	 bool validity;

 public:
    Customer();
    Customer(char*,char*,char*,char*,char*,char*); 	// this is use to set the customer name/email/address/password/code. 
    Customer Log_In();  							// this is use to login the customer/manger.
    void Sign_Up(); 								// this is use to register the customer.
    char* getemail() const;							// return the email address of the customer. 
    char* getpass() const;							// return the password of the customer.
    char* getname() const;							// return the name of the customer.
    char* getcode() const;							// return the manager code.
    void setcode(char*); 							// set the manager code.
    bool getValidity();								// returns the value of validity (true/false)
    void setValidity(bool);							// sets the value of validity
};

#endif
