#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef Food_H
#define Food_H

class Food {
private:
	int index;
	char* category;
	char* food_name;
	double price;
	
public:
	Food();	                                            						
	void Add_Data();																// use to add the food menu.		
	int Get_Index() const;															// returns to index number.
	char* Get_FoodName() const;  													// returns the food name.
	double Get_Price() const;														// return the food price.
	void Set_Data(int, char*, char*, double);										// use to set the index/category/foodname/price.
	void Display();																	// display details about food objects.
	void Show_Food(int);                                   							// use to display the menu.
	int* Food_Customization(Food* Final_Array, int count);                          // for food customization
	void Display2();																// display details about food objects except index.
};
#endif
