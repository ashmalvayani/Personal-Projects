#include <iostream>
#include "DeliveryServices.h"
#include "Food.h"
#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctime>
#include <windows.h>
#include "Order.h"
using namespace std;

#ifndef DELIVERY_H      // header guard
#define DELIVERY_H      // to avoid duplication

class Delivery{
	string rider;
	string phone;
	int Time;

public:
	void gotoxy(int,int); 				// move the cursor position. 
    Delivery(); 						// initiallize the default values.
	Food* Schedule_Order(Customer); 	// this is use to schedule the order.
    void Tracking(Food*,int);			// this is use to track the order.
};
#endif
