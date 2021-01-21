#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Food.h"
#include "Food.cpp"
#include "Order.h"
#include "Order.cpp"
#include "Customer.h"
#include "Cus.cpp"
#include "Delivery.h"
#include "Delivery.cpp"
#include "DeliveryServices.h"
#include "DeliveryServices.cpp"
#include "MyException.h"
#include "MyException.cpp"
using namespace std;

int main(){
    int count=0, choice,n,z=1, cho, back=0;
    char ch;

	Order ob;
    Customer cus, cus2;
    ob.Add_Data();
    Food* Final_Array;
    Delivery de;
    DeliveryServices object;
	object.Intro();
	object.loading();
    
	do{
		cout << "\n\n\tPlease Select Between The Following Options!\n";
		cout << "\n\t1. Login" << endl << "\t2. Sign Up" << endl << "\t3. Exit";
		cout << "\n\n\tEnter your choice :\t";
        cin >> choice;
        switch(choice){
        	case 1:
        		system("cls");
                cout << "\t\t\t***LOG IN***" << endl;
                cus2 = cus.Log_In();
                if(!cus2.getValidity()){
                	cout << "\n\nPress any key to go back to the main menu...";
	                getch();
	        		break;
				}
				else{
					cout << "\n\nPress any key to continue ..\t";
					getch();
					system("cls");
					do{
						cout << "\n\n\tNow Select Between The Following Options!\n";
						cout << "\n\t1. Show Menu" << endl << "\t2. Track Order" << endl << "\t3. Schedule your order" << endl << "\t4. Feedback" << endl << "\t5. Go back";
						cout << "\n\n\tEnter your choice :\t";
						cin >> cho;
						switch(cho){
							case 1:
								system("cls");
				                Final_Array= ob.show_menu(cus2);
				                count = ob.get_count();
				                cout << "\n\nPress any key to go back to the options..";
				                getch();
				                break;
							case 2:
								system("cls");
				                de.Tracking(Final_Array,count/2);
				                cout << "\n\nPress any key to go back to the options..";
				                getch();
				                break;
							case 3:
								system("cls");
				                Final_Array= de.Schedule_Order(cus2);
				                cout << "\n\nPress any key to go back to the options..";
				                getch();
				                break;
							case 4:
								system("cls");
				                object.feed_back();
				                break;
				            case 5:
				            	back=1;
				            	break;
				            default:
				            	cout << "\n\tINVALID ENTRY!";
				            	cout << "\n\tPLEASE ENTER THE CORRECT KEY...";
				            	getch();
				                break;
						}
						system("cls");
					}while(back==0);
				}
                break;
        	case 2:
        		cus.Sign_Up();
                cout << "\n\nPress any key to go back to the main menu...";
                getch();
        		break;
        	case 3:
        		if(remove("Customer.txt") && remove("Order.txt")); // do nothing function, just want to remove files
                exit(0);
            default:
            	cout << "\n\tINVALID ENTRY!";
            	cout << "\n\tPLEASE ENTER THE CORRECT KEY...";
            	getch();
                break;
		}
		system("cls");
	}while(true);
    return 0;
}
