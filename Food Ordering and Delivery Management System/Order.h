#include <iostream>
#include <fstream>
#include <string>
#include "Food.h"
#include "Customer.h"
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include "MyException.h"
using namespace std;

#ifndef ORDER_H      // header guard
#define ORDER_H      // to avoid duplication

class Order: public Food{
private:
    int order_number;
    static double total_price;
    static double tax;
	char* time_dispatch;
    int count;
	
public:
    void gotoxy(int,int); 						// move the cursor position. 
    Order();  									// constructor
    Order(int, double, double, char*);			//this will set the order number, total amount , tax and time.
	void Bill(Food*, int, int*, Customer); 		// this will generate the bill.
    Food* Order_Now(int *ptr, int count);		// this will take the order.
    int get_OrderNo() const;		 			// this will return the order no.
    double get_totalprice() const; 				// this will return the total amount of which customer ordered.
    double get_tax() const;       				// this will return the tax.
    Food* show_menu(Customer);					// this will show the menu to the customer.
    int get_count() const;						// this will return the value of count.
    
    friend class DeliveryServices;  			// friend class 
};

#endif
