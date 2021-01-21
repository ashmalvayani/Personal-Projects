#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <regex>
using namespace std;

#ifndef DeliveryServices_H
#define DeliveryServices_H

class DeliveryServices{
 private:
   double revenue;
   double tax;
   static string feed;
 public: 
   DeliveryServices();	
   void gotoxy(int,int); 					// move the cursor position. 
   void loading();							// 	this is use to hold the user for a while.
   void Intro();							// this function is use to make a welcome page.
   void feed_back(); 						// use to take feedback of food/service from customers.
   static bool check_date(int, int ,int); 	// this is use to check the date. 
   static bool Email_check(string);			// this is use to check the validity of email address.
   static void Manager_Portal();  			// this function is use to view total revenue and total tax to the manager.
   static char* mask_password();   			// this is use to mask the customer password.
   static char* check_phone();     			// this use to check the phone number pattern. 
};

#endif
