#include "Delivery.h"
// #include "DeliveryServices.h"

Delivery:: Delivery(){
	int Time=0;
    string phone="";
    string rider="";
}

Food* Delivery:: Schedule_Order(Customer cus2){
    Food* Final_Array;
    int date, month, year;
    bool check= true;

    do{
        cout << "Enter date in sequence: Date, Month, Year (DD/MM/YYYY)\t";
        scanf ("%d/%d/%d", &date, &month, &year);
        check = DeliveryServices::check_date(date,month,year);
    }while (check==false);

    Order ob;
    Final_Array= ob.show_menu(cus2);
    cout << "\n\nWe will contact you one day prior your date for reminder" << endl;
    return Final_Array;
}

void Delivery :: gotoxy (int x, int y)
{
    COORD coordinates;     // coordinates is declared as COORD
    coordinates.X = x;     // defining x-axis
    coordinates.Y = y;     //defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void Delivery:: Tracking(Food* Final_Array,int count){ // added count in func argument.
    int k=0, or_no;

    system("cls");
    cout << "\t\t\t***TRACKING YOUR ORDER***" << endl<<endl;
    cout << "Enter your Order Number : \t";
    cin >> or_no;

    ifstream ptr("Order.txt");
    if(!ptr){
    	cout << "\nNo Order Found!"<<endl;
       return ;
    }
    Order ob;
    ptr.read((char*)&ob,sizeof((ob)));
    while(!ptr.eof()){
	    if(ob.get_OrderNo()==or_no){
	    	k=1;
	        string Riders[4][2]={"Sohail","090078601",
	                     "Asad","090078602",
	                     "Kamran", "090078603",
	                     "Abdullah","090078604"};
    
            srand (time(NULL));
            int b= rand()%3+1;

            for(int i=0; i<4; i++){
                if(i==b){
                    rider=Riders[i][0];
                    phone=Riders[i][1];
                }
            }

            srand (time(NULL));
            Time = rand()% 50+1;

             system("cls"); // addtional start
			int i;
			gotoxy(15,1);
	        for( i=0; i<40; i++)
	        {
		     cout << "_";
	        }
	        gotoxy(16,2);
	        for( i=0; i<38; i++)
	        {
		     cout<<"*";
	        }
	        gotoxy(28,3);
	        cout << "TRACKING ORDER";
	        gotoxy(16,4);
	        for( i=0; i<38; i++)
	        {
		     cout << "*";
	        }
	
	        gotoxy(16,27);
	        for( i=0; i<38; i++)
	        {
		     cout << "-";
	        }
	        gotoxy(26,28);
	        cout << "****THANKYOU****";
	        gotoxy(18,29);
	        cout << " FOOD ORDERING AND DELIVERY SERVICES";
	         gotoxy(16,8);
	         cout << "FOOD ITEMS:";
	        int j=10;
 			 for(int i=0; i<count; i++){
  			gotoxy(28,j);
  			cout <<"~"<<Final_Array[i].Get_FoodName();
			  j++;
  			}
  			j=j+2;
  			gotoxy(16,j);
  			cout << "Total Price : " ;
		  	gotoxy(42,j);
  			cout << "Rs."<<ob.get_totalprice()<< "\-";
  			j++;
  			gotoxy(16,j);
  			cout << "Time left : " ;
  			gotoxy(42,j);
  			cout << Time << "mins";
  			j++;
  			gotoxy(16,j);
			cout << "Rider's Name: ";
			gotoxy(42,j);
  			cout << rider;
			j++;
			gotoxy(16,j);
 			cout << "Rider's Phone: ";
  			gotoxy(42,j);
  			cout << phone; 
  		
	        for( i=2; i<31; i++)
	        {
	        	gotoxy(14,i);
	        	cout << "|";
	        	gotoxy(55,i);
	        	cout << "|";
			}
				gotoxy(15,30);
			for(int i=0; i<40; i++)
	        {
		     cout << "_";
	        } 
            break;
        }
        if(!k)
            ptr.read((char*)&ob,sizeof((ob)));
    }
    if(k==0){
        cout << "No Order found with that number." << endl;
    }
}
