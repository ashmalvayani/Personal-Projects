#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>
#include "BST.h"
#include "BSTT.cpp"
#include "Context_Free_Grammar.h"
#include "Context_Free_Grammar.cpp"
using namespace std;
	
int main()
{
	string input;
	int choice;
	MenuDriven Menu;
	Menu.Intro();
	BinarySearchTree Tree;
	system("cls");
	do{
		cout << "\n\n\tPlease Select Between The Following Options!\n";
		cout << "\n\t1. Login\n" << endl << "\t2. Sign Up\n" << endl << "\t3. Exit\n";
		cout << "\n\n\tEnter your choice :\t";
		cin >> choice;
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "\n\tINVALID ENTRY!\n\n";
				cout << "\n\tPLEASE ENTER THE CORRECT KEY...\t";
				cin>>choice;
			}
			break;
		}
		
		switch(choice){
			case 1:
				// login 
				system("cls");
				cout << "\t\t\t***LOG IN***\n\n" << endl;
				if(Tree.Login()){
					cout << "\tLOGIN SUCCESSFUL...\n";
					system("cls");
					cout << "\t\t\t***GRAMMAR CHECKER!***\n\n";
					cout << "\nEnter sentence to check its grammar:\t";
				
					Context_Free_Grammar* Machine = new Context_Free_Grammar();
					Machine->Start_Program();
				}
				else{
					cout << "\tCAN'T LOGIN!.\n";
				}
				gotoxy(1,25);
				cout << "\n\nPress any key to go back to the main menu...\n";
				getch();
				break;

			case 2:
			//sign up
				system("cls");
				cout << "\t\t\t***SIGN UP***\n\n" << endl;
				Tree.SignUp();
				cout << "\n Any key to go back to the main menu...\n";
				getch();
				break;
			case 3:
			
				exit(0);
			default:
				cout << "\n\tINVALID ENTRY!\n";
				system("cls");
				cout << "\n\tPLEASE ENTER THE CORRECT KEY...";
				getch();
				break;
		}
		system("cls");
	}while(true);
	
    return 0;
}
