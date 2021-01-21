#include "MenuDriven.h"
#include "Queue.cpp"
#include <iostream>
using namespace std;

MenuDriven::MenuDriven(){}

bool MenuDriven:: Email_check(string email){
    const regex pattern("^[a-zA-Z0-9_.+-]+@(?:(?:[a-zA-Z0-9-]+\\.)?[a-zA-Z]+\\.)?(edu)\\.(pk)$");
    return regex_match(email,pattern);
}

void MenuDriven:: Intro(){
    int i,j;
	system("cls");
	
	system("color 70");
	
	gotoxy(35,3);
	for(i=0;i<59;i++){	
		for(j=0;j<=3000000;j++);
			cout << "\xB2";
	}
	for(i=4; i<30; i++)
	{
	gotoxy(93,i);
	for(j=0;j<=3000000;j++);
	cout << "\xB2";
	}
	int k=93;
	
for(i=0; i<58; i++)
{
	gotoxy(k,30);
	k--;
	for(j=0;j<=3000000;j++);
 	cout << "\xB2";
}

	 for(i=30; i>3; i--)
 	{
 	gotoxy(35,i);
	 for(j=0;j<=3000000;j++);
 	cout << "\xB2";
 	}

	gotoxy(39,6);
	for(i=0;i<50;i++)
	{
		for(j=0;j<=3000000;j++);
		cout <<"\xB2";
	}
	gotoxy(44,9);
	cout << "WELCOME TO CONTEXT FREE GRAMMAR CHECKER";
	gotoxy(39,12);
		for(i=0;i<50;i++)
	{
		for(j=0;j<=3000000;j++);
		cout <<"\xB2";
	}
	gotoxy(56,16);
	for(j=0;j<=30000000;j++);
	cout << " DEVELOPED BY";
	gotoxy(56,18);
	for(j=0;j<=30000000;j++);
	cout << "ASHMAL VAYANI";
	gotoxy(56,19);
	for(j=0;j<=30000000;j++);
	cout << " ABDUL SAMAD";
	gotoxy(56,20);
	for(j=0;j<=30000000;j++);
	cout << "HASNAIN SOMANI";
	
    gotoxy(49,25); 
	cout <<"(Press Any Key To Continue)";
    getch();
} 

string MenuDriven:: mask_password(){
    string password = "";
    char ch;
    int i;

    while(1){
        ch = _getch();
        if(ch==13)
            break;
        else if(ch == 9 || ch == 32)
            continue;
        else if(ch==8){
            if(i>0){
                i--;
                cout << "\b \b";
            }
        }
        else if(ch >=32 && ch <= 127){
            password+= ch;
            cout << "*";
        }
        else{
			continue;
        }
    }
    cout << endl;
    return password;
}
