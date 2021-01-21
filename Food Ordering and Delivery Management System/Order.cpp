#include "Order.h"
#include <windows.h> // additional

double Order:: total_price =0;
double Order:: tax=0;
Order:: Order(){
    order_number=0;
	time_dispatch=0;
    count=0;
}
Order:: Order(int num, double price, double t, char* time){
    order_number=num;
    total_price=price;
    tax=t;
    time_dispatch= time;
}
Food* Order:: Order_Now(int* ptr, int count){
    static Food* Array= new Food[count/2];
    int j=0;
    Food ob;
    for(int i=0; i<count; i+=2, j++){
        if(ptr[i]==1){
            ifstream italian("Italian.txt");
            if (!italian)
                exit(0);

            italian.read((char*)&ob, sizeof(ob));
            while (!italian.eof()) {
                if(ob.Get_Index()==ptr[i+1]){
                    Array[j]=ob;
                }
                italian.read((char*)&ob, sizeof(ob));
            }
            italian.close();
        }
        else if(ptr[i]==2){
            ifstream chinese("Chinese.txt");
            if (!chinese)
                exit(0);
            chinese.read((char*)&ob, sizeof(ob));
            while (!chinese.eof()) {
                if(ob.Get_Index()==ptr[i+1])
                    Array[j]=ob;
                chinese.read((char*)&ob, sizeof(ob));
            }
            chinese.close();
        }
        else if(ptr[i]==3){
            ifstream fastfood("FastFood.txt");
            if (!fastfood)
                exit(0);
            fastfood.read((char*)&ob, sizeof(ob));
            while (!fastfood.eof()) {
                if(ob.Get_Index()==ptr[i+1]){
                    Array[j]=ob;
                }
                fastfood.read((char*)&ob, sizeof(ob));
            }
            fastfood.close();
        }
        else if(ptr[i]==4){
            ifstream bbq("BBQ.txt");
            if (!bbq)
            exit(0);
            bbq.read((char*)&ob, sizeof(ob));
            while (!bbq.eof()) {
                if(ob.Get_Index()==ptr[i+1]){
                    Array[j]=ob;
                }
                bbq.read((char*)&ob, sizeof(ob));
            }
            bbq.close();
        }
        else if(ptr[i]==5){
            ifstream beverages("Beverages.txt");
            if (!beverages)
                exit(0);

            beverages.read((char*)&ob, sizeof(ob));
            while (!beverages.eof()) {
                if(ob.Get_Index()==ptr[i+1]){
                    Array[j]=ob;
                }
                beverages.read((char*)&ob, sizeof(ob));
            }
            beverages.close();
        }
        else if(ptr[i]==6){
            ifstream desserts("Desserts.txt");
            if (!desserts)
                exit(0);
            desserts.read((char*)&ob, sizeof(ob));
            while (!desserts.eof()) {
                if(ob.Get_Index()==ptr[i+1]){
                    Array[j]=ob;
                }
                desserts.read((char*)&ob, sizeof(ob));
            }
            desserts.close();
        }
    }
    cout << "\n------------------------------------------";
    cout << "\nTHE TOTAL ITEMS THAT YOU'VE SELECTED!" << endl << endl;
    for(int i=0; i<j; i++){
        cout << "Item# " << i+1 << ": "; 
		Array[i].Display2();
    }
    cout << "------------------------------------------";
    cout << "\n\nPress any key to confirm your order." << endl;
    getch(); 
    return Array;
}

void Order:: gotoxy (int x, int y){
	COORD coordinates;         // coordinates is declared as COORD
	coordinates.X = x;         // defining x-axis
 	coordinates.Y = y;         //defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
    
void Order:: Bill(Food* Final_Array, int count, int* price, Customer cus){
    total_price=0;
    double discount=0, premium_price=0, dis=0;
	for(int i=0; i<count; i++)
		total_price = total_price + Final_Array[i].Get_Price() + price[i];
	tax= total_price * 0.14;
    total_price += tax;

    if(cus.getcode()=="PREMIUM10"){
        discount=10;
        premium_price = 500;
    }        
    else if(cus.getcode()=="PREMIUM20"){
        discount = 20;
        premium_price= 900;
    }        
    else if(cus.getcode()=="PREMIUM30"){
        discount = 30;
        premium_price= 1500;
    }
    else
        discount=0;
    
    dis= total_price*(discount/100.0);
    total_price -= dis; 
    total_price += premium_price;

    order_number = 1;
    
    time_t my_time = time(NULL);
    tm* now= localtime(&my_time);
    time_dispatch= ctime(&my_time);
    int d= now->tm_mday;
	int m= now->tm_mon;
	int y= now->tm_year+1900;
    int h= now->tm_hour;
    int mi= now->tm_min;
    string zone;
    int x;
    x=count-6;

    ofstream ptr("Order.txt");
    if(!ptr){
        exit(0);
    }
    Order ob(order_number,total_price,tax,time_dispatch);
    ptr.write((char*)&ob,sizeof(ob));
    ptr.close();
    system("cls");
    cout << "\t\t\t***Printing Bill***" <<endl;
    int i,c=0;
    if (count >0 && count <=6)
    {
		gotoxy(15,1);
        for(i=0; i<40; i++)
        {
	     cout << "_";
        }
        gotoxy(16,2);
        for(i=0; i<38; i++)
        {
	     cout<<"*";
        }
        gotoxy(30,3);
        cout << "RECEIPT";
        gotoxy(30,7);
	    cout << "ORDER #" << order_number ;
        
        int j=8;
        for(int i=0; i<count; i++){
        gotoxy(16,j);
        cout << Final_Array[i].Get_FoodName();
        gotoxy(44,j);
	    cout << "Rs." << Final_Array[i].Get_Price() << "/-";
        j++;
         gotoxy(16,j);
  		cout << "Customization: ";
 		gotoxy(44,j);
 		cout << price[i];
  		j=j+2;
        c=c+3;
        }
        
        gotoxy(16,4);
        for(i=0; i<38; i++)
        {
	     cout << "*";
        }
        gotoxy(36,5);
        cout << d <<"/" << m << "/" << y <<" ";

        if(h>12)
        {
         if(h==24)
        {
        
          zone="AM";
          h-=12;
        }
         else{
          h-=12;
          zone="PM";
        }
        }
        else
        {
            zone = "AM";
        }
        
        cout << h << ":" << mi << " " << zone;
        gotoxy(16,5);
        cout << "Customer: " << cus.getname();
        gotoxy(16,6);
        for(i=0; i<38; i++)
        {
	     cout << "-";
        }
        gotoxy(16,c+7);
        for(i=0; i<38; i++)
        {
	     cout << "-";
        }
        gotoxy(16,c+8);
        cout << "TOTAL:";
        gotoxy(42,c+8);
        cout << "Rs." << total_price+discount*(total_price/100.0)<< "/-";
        gotoxy(16,c+9);
        cout << "DISCOUNT:";
        gotoxy(42,c+9);
        cout << discount <<"%";
        
        gotoxy(16,c+10);
        cout << "TAX(14%):";
        gotoxy(42,c+10);
        cout << "Rs." <<tax << "/-";
        
        gotoxy(16,c+11);
        cout << "PREMIUM CHARGES:";
        gotoxy(42,c+11);
        cout << "Rs." << premium_price << "/-" ;
        
        gotoxy(16,c+12);
        cout << "NET TOTAL:";
         gotoxy(42,c+12);
        cout << "Rs."<< total_price << "/-" ;
        gotoxy(16,c+13);
        for(i=0; i<38; i++)
        {
	     cout << "-";
        }
        gotoxy(26,c+14);
        
        cout << "****THANKYOU****";
        gotoxy(18,c+15);
        cout << " FOOD ORDERING AND DELIVERY SERVICES";
        
        for(i=2; i<(17+c); i++)
        {
        	gotoxy(14,i);
        	cout << "|";
        	gotoxy(55,i);
        	cout << "|";
		}
			gotoxy(15,c+16);
		for(i=0; i<40; i++)
        {
	     cout << "_";
        }
    }
    if(count >6 && count <=12)
    {
        gotoxy(15,1);
    for(i=0; i<75; i++)
    {
     cout << "_";
    }
    gotoxy(15,2);
    for(i=0; i<75; i++)
    {
     cout<<"*";
    }
    gotoxy(45,3);
    cout << "RECEIPT";
    gotoxy(45,5);
    cout << "ORDER #" << order_number ;

    int j=8;
    for(int i=0; i<6; i++){
    gotoxy(16,j);
    cout << Final_Array[i].Get_FoodName();
    gotoxy(43,j);
    cout << "Rs." << Final_Array[i].Get_Price()<< "/-";
    j++;
     gotoxy(16,j);
    cout << "Customization: ";
    gotoxy(44,j);
    cout << price[i];
    j=j+2;
    c=c+3;
    }
    
    	for(i=7; i<25; i++)
    {
    	gotoxy(52,i);
    	cout << "|";
    }
    	j=8;
    for(int i=6; i <count ; i++)
    {
    	gotoxy(53,j);
    	cout << Final_Array[i].Get_FoodName();
    	gotoxy(81,j);
    	cout << "Rs." << Final_Array[i].Get_Price()<< "/-";
    	j++;
     	gotoxy(53,j);
    	cout << "Customization: ";
    	gotoxy(81,j);
    	cout << price[i];
    	j=j+2;
    }

    gotoxy(15,4);
    for(i=0; i<75; i++)
    {
     cout << "*";
    }
    gotoxy(60,5);

    	cout << time_dispatch;

    gotoxy(16,5);
    cout << "Customer: " << cus.getname();
    gotoxy(15,6);
    for(i=0; i<75; i++)
    {
     cout << "-";
    }
    gotoxy(15,c+7);
    for(i=0; i<75; i++)
    {
     cout << "-";
    }
    gotoxy(16,c+8);
    cout << "TOTAL:";
    gotoxy(75,c+8);
    cout << "Rs." << total_price+discount*(total_price/100.0)<< "/-";
    gotoxy(16,c+9);
    cout << "DISCOUNT:";
    gotoxy(75,c+9);
    cout << discount <<"%";
     	 
    gotoxy(16,c+10);
    cout << "TAX(14%):";
    gotoxy(75,c+10);
    cout << "Rs." <<tax << "/-";
          
    gotoxy(16,c+11);
    	cout << "PREMIUM CHARGES:";
    gotoxy(75,c+11);
    cout << "Rs." << premium_price << "/-" ;
          
    gotoxy(16,c+12);
    cout << "NET TOTAL:";
     gotoxy(75,c+12);
    cout << "Rs."<< total_price << "/-" ;
    	
    gotoxy(15,c+13);
    for(i=0; i<75; i++)
    {
     cout << "-";
    }
    gotoxy(42,c+14);

    cout << "****THANKYOU****";
    gotoxy(34,c+15);
    cout << " FOOD ORDERING AND DELIVERY SERVICES";

    for(i=2; i<(17+c); i++)
    {
    	gotoxy(14,i);
    	cout << "|";
    	gotoxy(90,i);
    	cout << "|";
    }
    	gotoxy(15,c+16);
    for(i=0; i<75; i++)
    {
     cout << "_";
    }
    }
    if (count > 12 )
    {
        cout << "Sorry, We can't take more than 12 item order.";
    }
}

int Order:: get_OrderNo() const{
    return order_number;
}
double Order:: get_totalprice() const{
    return total_price;
}
double Order:: get_tax() const{
    return tax;
}
int Order:: get_count() const{
    return count;
}

Food* Order::show_menu(Customer cus2){
    int* ptr;
    int cat, index,z=1, i=0;
    char ch;
    static Food* Final_Array;

    ptr= (int*)calloc(2,sizeof(int));
    if(!ptr){
        cout << "Failed memory allocation" << endl;
        exit(0);
    }
	system("cls");
    while(z==1){
    	cout << "\t\t\t***MENU***";
    	cout << "\n\nCATEGORIES WE HAVE: " << endl << "1. Italian" << endl << "2. Chinese" << endl << "3. Fast Food" << endl << "4. BBQ" << endl << "5. Beverages" << endl << "6. Desserts" << endl;
        do{
            try{
                cout << "\nEnter the category number you want to look-in : "; 
                cin >> cat;
                if(cat >6 ||cat <=0)
                    throw cat;
            }
            catch(int a){
                cout << a << " is an invalid number." << endl << endl;
               	getch();                                       
            }
        }while(cat<=0 ||cat>6);
        
		Show_Food(cat);
        bool condition=true;
        do{
        	try{
                cout << "\nEnter the option number to add to cart : ";
                cin >> index;
                if(cat==1 && (index<1 || index>6)){
                	condition=false;
                	throw MyException(index);
				}
				else if(cat==2 && (index<1 || index>3)){
					condition=false;
					throw MyException(index);
				}
				else if(cat==3 && (index<1 || index>4)){
					condition=false;
					throw MyException(index);
				}
				else if(cat==4 && (index<1 || index>3)){
					condition=false;
					throw MyException(index);
				}
				else if(cat==5 && (index<1 || index>4)){
					condition=false;
					throw MyException(index);
				}
				else if(cat==6 && (index<1 || index>3)){
					condition=false;
					throw MyException(index);
				}
				else
					condition=true;
			}
			catch(MyException& ob){
				cout << ob.what();
			}
		}while(condition==false);

        ptr[i++]=cat;
        ptr[i++]=index;
        count+=2;
        cout << "Do you want to order anything else? (Y/N)\t";
        cin >> ch;
        if(ch=='y'|| ch=='Y'){
            ptr=(int*)realloc(ptr,(count+2)*sizeof(int));
            if(!ptr){
                cout << "Failed memory allocation" << endl;
                exit(0);
            }
        }
        else{
            z=0;
            Final_Array= Order_Now(ptr,count);
            int* price= Food_Customization(Final_Array,count/2);
            Bill(Final_Array,count/2, price, cus2);
        }
    }
        return Final_Array;
}
