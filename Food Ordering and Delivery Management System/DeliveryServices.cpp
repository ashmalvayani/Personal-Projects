#include "DeliveryServices.h"
#include <conio.h>

DeliveryServices:: DeliveryServices(){
	string feed="";
}
void DeliveryServices:: gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}

string DeliveryServices:: feed="";
void DeliveryServices:: loading(){
    int i ,j;
	system("cls");
	gotoxy(55,16);
	cout << "LOADING PLEASE WAIT...";
	gotoxy(55,18);
 	cout <<"=====================";
	gotoxy(54,19);
	cout <<"|";
	gotoxy(75,19);
	cout <<(" | ");
	gotoxy(55,20);
	cout <<"=====================";
 	gotoxy(55,19);
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=10000000;j++);
			cout <<"\xB2";
	}
	system("cls");	
}
void DeliveryServices:: Intro(){
  int i,j;
	system("cls");
	gotoxy(35,3);
	for(i=0;i<59;i++)
	{	for(j=0;j<=3000000;j++);
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
	gotoxy(39,9);
	cout << "WELCOME TO FOOD ORDERING AND DELIVERY SERVICES";
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
	cout << "HASNAIN SOMANI";
	gotoxy(56,20);
	for(j=0;j<=30000000;j++);
	cout << "ABDUL SAMAD";
	
    gotoxy(49,25); 
	cout <<"(Press Any Key To Continue)";
    getch();
}
void DeliveryServices:: feed_back(){
    int l, k=1;
	gotoxy(34,2);
	for(int i=0;i<59;i++)
	{
		cout << "\xB2";
	}
		gotoxy(34,25);
	for(int i=0;i<59;i++)
	{
		cout << "\xB2";
	}
	gotoxy(54,4);
	cout << "~~~FEEDBACK~~~";
	gotoxy(34,6);
	cout << "THANKYOU FOR CHOOSING FOOD ORDERING AND DELIVERY SERVICES,";
	gotoxy(34,7);
	cout << "WE'RE GLAD TO HAVE YOU AS OUT CUSTOMER!";
	gotoxy(34,9);
	cout << "Write your feedback:";
	fflush(stdin);
	gotoxy(34,10);
	getline(cin,feed);
	transform(feed.begin(), feed.end(), feed.begin(), ::tolower); 
	l=feed.size();
	for(int i=0; i<l; i++){
		if(feed[i]=='b' && feed[i+1]=='a' && feed[i+2]=='d'){
				gotoxy(30,19);
				cout << "-------------------------------------------------------------------";
				gotoxy(30,20);
				cout << "Sorry for the inconvenience, we are trying to improve our services." ;
				gotoxy(30,21);
				cout << "-------------------------------------------------------------------";
			k=1;
			break;
		}
		else if(feed[i]=='w' && feed[i+1]=='o' && feed[i+2]=='r' && feed[i+3]=='s'&& feed[i+4]=='t'){
		
				gotoxy(30,19);
				cout << "-------------------------------------------------------------------";
				gotoxy(30,20);
				cout << "Sorry for the inconvenience, we are trying to improve our services." ;
				gotoxy(30,21);
				cout << "-------------------------------------------------------------------";
			k=1;
			break;
		}
		else if(feed[i]=='t' && feed[i+1]=='a' && feed[i+2]=='s'&& feed[i+3]=='t'&& feed[i+4]=='e'&& feed[i+5]=='l'&& feed[i+6]=='e'&& feed[i+7]=='s'&& feed[i+8]=='s'){
				gotoxy(30,19);
				cout << "-------------------------------------------------------------------";
				gotoxy(30,20);
				cout << "Sorry for the inconvenience, we are trying to improve our services." ;
				gotoxy(30,21);
				cout << "-------------------------------------------------------------------";
				k=1;
			break;
		}
		else if(feed[i]=='p' && feed[i+1]=='o' && feed[i+2]=='o'&& feed[i+3]=='r'){
				gotoxy(30,19);
				cout << "-------------------------------------------------------------------";
				gotoxy(30,20);
				cout << "Sorry for the inconvenience, we are trying to improve our services." ;
				gotoxy(30,21);
				cout << "-------------------------------------------------------------------";
			k=1;
			break;
		}
		else if(feed[i]=='g' && feed[i+1]=='o' && feed[i+2]=='o' && feed[i+3]=='d'){
			gotoxy(38,19);
				cout << "---------------------------------------------";
				gotoxy(41,20);
			cout << "We are glad that you liked our services" ;
				gotoxy(38,21);
				cout << "---------------------------------------------";
			k=1;
			break;
		}
		else if(feed[i]=='e' && feed[i+1]=='x' && feed[i+2]=='c' && feed[i+3]=='e'&& feed[i+4]=='l'&& feed[i+5]=='l'&& feed[i+6]=='e'&& feed[i+7]=='n'&& feed[i+8]=='t'){
			gotoxy(38,19);
				cout << "---------------------------------------------";
					gotoxy(41,20);
			cout << "We are glad that you liked our services" ;
				gotoxy(38,21);
				cout << "---------------------------------------------";
			k=1;
			break;
		}
		else if(feed[i]=='d' && feed[i+1]=='e' && feed[i+2]=='l' && feed[i+3]=='i'&& feed[i+4]=='c'&& feed[i+5]=='i'&& feed[i+6]=='o'&& feed[i+7]=='u'&& feed[i+8]=='s'){
			gotoxy(38,19);
				cout << "---------------------------------------------";
				gotoxy(41,20);
			cout << "We are glad that you liked our services" ;
				gotoxy(38,21);
				cout << "---------------------------------------------";
			k=1;
			break;
		}
		else{
			k=0;
		}
	}
	if(k==0){
		gotoxy(38,22);
		cout << "Your suggestion is valuable to us!";
	}	
	gotoxy(34,23);
	cout << "Press Any Key To Continue!";
	getch();	
}

bool DeliveryServices:: check_date(int date ,int month, int year){
	time_t t = time(0);
	tm* now= localtime(&t);
	int d= now->tm_mday;
	int m= now->tm_mon;
	int y= now->tm_year+1900;
	int z=1, k=0;
	if (date < 0 || month>12){
		cout << "Invalid date!\n";
		z=0;
	}
	else if(((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12)) && date>31){
		cout << "Invalid date!\n";
		z=0;
	}
	else if((month==4 || month==6 || month==9|| month==11) && date>30){
		cout << "Invalid date!\n";
		z=0;
	}
	else if(month==2 && date>=29){
		if(!(year%4==0 || (year%100==0 && year%400==0))){
			cout << "Invalid date! " << year << " is not a leap year\n";
			z=0;
		}
	}
	else{
		while(k==0){
			k=1;
			if(year < y){
				cout << "The date you have entered has passed, Kindly enter again.\n";
				k=0;
				z=0;
				break;
			}
			else if(year ==y && month < m){
				cout << "The date you have entered has passed, Kindly enter again.\n";
				k=0;
				z=0;
				break;
			}
			else if(year ==y && month ==m && date<d){
				cout << "The date you have entered has passed, Kindly enter again.\n";
				k=0;
				z=0;
				break;
			}
			else
				k=1;
			}
	}
	if(k==0 && z==0)
		return false;
	else
		return true;
}

bool DeliveryServices:: Email_check(string email){
	const regex pattern("^[a-zA-Z0-9_.+-]+@(?:(?:[a-zA-Z0-9-]+\.)?[a-zA-Z]+\.)?(gmail|hotmail|yahoo)\.(com|pk|gov)$");
    return regex_match(email,pattern);
}

void DeliveryServices:: Manager_Portal(){
	int choice;
	char ch;
	Order ob;
	
	do{
		system("cls");
		cout << "\t\t\t***MANAGER PORTAL***\n";
		cout << "\n\n\tAs a manager you can perform these operations:\n\n\t1. View Total Revenue. \n\t2. View Total Tax. \n\t3. Review Feedbacks.";
		cout << "\n\n\tWhat would you like to do? (1-3):\t";
		cin >> choice;
		
		switch(choice){
		case 1:
			cout << "\n\t------------------------------------------------\n";
//			cout << "\tTotal Revenue : " << ob.get_totalprice()<< endl;
			cout << "\tTotal Revenue : " << ob.get_totalprice() << endl;
			cout << "\n\t------------------------------------------------\n";
			break;
		case 2:
			cout << "\n\t------------------------------------------------\n";
			cout << "\tTotal Tax : " << ob.get_tax() << endl;		
			cout << "\n\t------------------------------------------------\n";
			break;
		case 3:
			cout << "\n\t------------------------------------------------\n";
			cout << "\t\tREVIEWING FEEDBACKS\n";
			cout << "\tCustomer's Feedback : \t" << feed << endl;
			cout << "\n\t------------------------------------------------\n";
			break;
		default:
			cout << "\n\tInvalid choice. Please re-enter. \t";
			break;
		}
		cout << "\n\n\tDo you want to perform any other task? (y/n) :\t";
		fflush(stdin);
		ch=getche();
	}while(ch=='Y' || ch=='y');
}

char* DeliveryServices:: mask_password(){
	char* pass= new char[10];
	char ch;
	int i;
	while (1) {
    ch = _getch();
    if (ch == 13)
    	break;
    else if (ch == 9 || ch == 32)
    	continue;
    else if (ch == 8) {
    	if (i > 0) {
    	   i--;
        cout <<"\b \b";
      }
    } 
	else if(ch >= 32 && ch <= 127){
		pass[i++] = ch;
      	cout << "*";
    }
    else
    	continue;
  	}
  	return pass;
}

char* DeliveryServices:: check_phone(){
	char* phone= new char[11];
	regex r("[[:digit:]]{4}-[[:digit:]]{7}");
	do{
		cin >> phone;
		if (regex_match(phone, r))
	  		return phone;
	  	else 
	    	cout << "INVALID PHONE NUMBER, ENTER AGAIN!\n";
	}while(true);
}
