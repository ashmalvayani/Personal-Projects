#include "Food.h"

Food::Food() {
    index=0;
    category=0;
    food_name=0;
    price=0;
}
char* Food:: Get_FoodName() const{ // addtional
    return food_name; 
}
double Food::Get_Price() const{
	return price;
}
int Food:: Get_Index() const{
    return index;
}

void Food::Add_Data() {
	ofstream italian("Italian.txt");
    Food ob;
    if (!italian)
        exit(0);
    ob.Set_Data(1, "Italian", "Pizza-Small", 400);
    italian.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "Italian", "Pizza-Medium", 800);
    italian.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "Italian", "Pizza-Large", 1200);
    italian.write((char*)&ob, sizeof(ob));
    ob.Set_Data(4, "Italian", "Lasagna", 1000);
    italian.write((char*)&ob, sizeof(ob));
    ob.Set_Data(5, "Italian", "Steak", 900);
    italian.write((char*)&ob, sizeof(ob));
    ob.Set_Data(6, "Italian", "Italiano Pasta", 700);
    italian.write((char*)&ob, sizeof(ob));
    italian.close();

    ofstream chinese("Chinese.txt");
    if (!chinese)
        exit(0);
    ob.Set_Data(1, "Chinese", "Chow Mein", 450);
    chinese.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "Chinese", "Chicken Manchurian", 480);
    chinese.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "Chinese", "Chicken Shashlik", 500);
    chinese.write((char*)&ob, sizeof(ob));
    chinese.close();

    ofstream fastfood("FastFood.txt");
    if (!fastfood)
        exit(0);
    ob.Set_Data(1, "Fast Food", "Club Sandwitch", 250);
    fastfood.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "Fast Food", "Zinger Burger", 300);
    fastfood.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "Fast Food", "Chicken Burger", 210);
    fastfood.write((char*)&ob, sizeof(ob));
    ob.Set_Data(4, "Fast Food", "Beef Burger", 250);
    fastfood.write((char*)&ob, sizeof(ob));
    fastfood.close();

    ofstream bbq("BBQ.txt");
    if (!bbq)
        exit(0);
    ob.Set_Data(1, "BBQ", "Chicken Tikka", 200);
    bbq.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "BBQ", "Seekh Kabab", 170);
    bbq.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "BBQ", "Malai Boti", 190);
    bbq.write((char*)&ob, sizeof(ob));
    bbq.close();

    ofstream beverages("Beverages.txt");
    if (!beverages)
        exit(0);
    ob.Set_Data(1, "Beverages", "500 ml drink", 80);
    beverages.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "Beverages", "Mint Lemonade", 280);
    beverages.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "Beverages", "Cold Coffee", 180);
    beverages.write((char*)&ob, sizeof(ob));
    ob.Set_Data(4, "Beverages", "Juice", 50);
    beverages.write((char*)&ob, sizeof(ob));
    beverages.close();

    ofstream desserts("Desserts.txt");
    if (!desserts)
        exit(0);
    ob.Set_Data(1, "Desserts", "Lava Cake", 350);
    desserts.write((char*)&ob, sizeof(ob));
    ob.Set_Data(2, "Desserts", "Cookie", 150);
    desserts.write((char*)&ob, sizeof(ob));
    ob.Set_Data(3, "Desserts", "Red Velvet Sundae's", 200);
    desserts.write((char*)&ob, sizeof(ob));
    desserts.close();
}

void Food::Show_Food(int cat) {
    Food ob;
    if(cat==1){
        ifstream italian("Italian.txt");
        if (!italian)
            exit(0);
        italian.read((char*)&ob, sizeof(ob));
        while (!italian.eof()) {
            ob.Display();
            italian.read((char*)&ob, sizeof(ob));
        }
        italian.close();
    }
    else if(cat==2){
        ifstream chinese("Chinese.txt");
        if (!chinese)
            exit(0);
        chinese.read((char*)&ob, sizeof(ob));
        while (!chinese.eof()) {
            ob.Display();
            chinese.read((char*)&ob, sizeof(ob));
        }
        chinese.close();
    }
    else if(cat==3){
        ifstream fastfood("FastFood.txt");
        if (!fastfood)
            exit(0);
        fastfood.read((char*)&ob, sizeof(ob));
        while (!fastfood.eof()) {
            ob.Display();
            fastfood.read((char*)&ob, sizeof(ob));
        }
        fastfood.close();
    }
    else if(cat==4){
        ifstream bbq("BBQ.txt");
        if (!bbq)
        exit(0);
        bbq.read((char*)&ob, sizeof(ob));
        while (!bbq.eof()) {
            ob.Display();
            bbq.read((char*)&ob, sizeof(ob));
        }
        bbq.close();
    }
    else if(cat==5){
        ifstream beverages("Beverages.txt");
        if (!beverages)
        exit(0);
        beverages.read((char*)&ob, sizeof(ob));
        while (!beverages.eof()) {
            ob.Display();
            beverages.read((char*)&ob, sizeof(ob));
        }
        beverages.close();
    }
    else if(cat==6){
        ifstream desserts("Desserts.txt");
        if (!desserts)
            exit(0);
        desserts.read((char*)&ob, sizeof(ob));
        while (!desserts.eof()) {
            ob.Display();
            desserts.read((char*)&ob, sizeof(ob));
        }
        desserts.close();
    }
}

void Food::Display() {
	cout << index << "\t" << category << "\t" << food_name << "\t" << price << endl;
}

void Food:: Display2(){
    cout << category << "\t" << food_name << "\t" << price << endl;
}

void Food::Set_Data(int i, char* c, char* f, double p) {
	index = i;
	category = c;
	food_name = f;
	price = p;
}

int* Food:: Food_Customization(Food* Final_Array, int count){
    int choice;
    string* cus= new string[count];
    int* price= new int[count];
    
    system("cls");
    cout << "\t\t\t\t***FOOD CUSTOMIZATION***" << endl;
    cout << "You'll now be able to customize your order" << endl;
    for(int i=0; i<count; i++){
        if(Final_Array[i].category=="Italian"){
            cout << "\n\t\tFOR ITALIAN ITEMS!!!" << endl;
            cout << "1. Extra Cheese\t\t\t Rs.100/-\n2. Extra Sauce\t\t\t Rs.50/-\n3. Both Extra Cheese and Sauce\t Rs.150/-" << endl;
			cout << "----------------------------------------------";
			cout << "\nPress any other key for No Customization" << endl;
			cout << "----------------------------------------------" << endl;
            cout << "\nEnter Your Choice :\t";
            cin >> choice;
            if(choice==1){
                cus[i]="Extra Cheese";
                price[i]=100;
            }
            else if(choice ==2){
                cus[i]="Extra Sauce";
                price[i]=50;
            }
            else if(choice ==3){
                cus[i]="Both";
                price[i]=150;
            }
            else{
                cus[i]="No Customization";
                price[i]=0;
            }
        }

        else if(Final_Array[i].category=="Chinese"){
            cout << "\n\t\tFOR CHINESE ITEMS!!!" << endl;
            cout << "1. Extra Veges\t Rs.100" << endl;
            cout << "----------------------------------------------";
			cout << "\nPress any other key for No Customization" << endl;
			cout << "----------------------------------------------" << endl;
            cout << "\n\n Enter Your Choice :\t";
            cin >> choice;
            if(choice==1){
                cus[i]="Extra Veges";
                price[i]=100;
            }
            else{
                cus[i]="No Customization";
                price[i]=0;
            }
        }
        else if(Final_Array[i].category=="Fast Food"){
            cout << "\n\t\tFOR FAST FOOD ITEMS!!!" << endl;
            cout << "1. Extra Fries\t Rs.100/- \n2. Special Sauce\t Rs.50/-\n3. Both Fries and Sauce\t Rs.150/-\n";
            cout << "----------------------------------------------";
			cout << "\nPress any other key for No Customization" << endl;
			cout << "----------------------------------------------" << endl;
            cout << "\n\n Enter Your Choice :\t";
            cin >> choice;
            if(choice==1){
                cus[i]="Extra Fries";
                price[i]=100;
            }
            else if(choice ==2){
                cus[i]="Special Sauce";
                price[i]=50;
            }
            else if(choice ==3){
                cus[i]="Both";
                price[i]=150;
            }
            else{
                cus[i]="No Customization";
                price[i]=0;
            }
        }
        else if(Final_Array[i].category=="BBQ"){
            cout << "\n\t\tFOR BBQ ITEMS!!!" << endl;
            cout << "1. Salad\t Rs.50/-\n2. Creamy topping\t Rs.150/-\n3. Both Salad and Creamy topping\t Rs.200/-\n";
            cout << "----------------------------------------------";
			cout << "\nPress any other key for No Customization" << endl;
			cout << "----------------------------------------------" << endl;
            cout << "\n\n Enter Your Choice :\t";
            cin >> choice;
            if(choice==1){
                cus[i]="Salad";
                price[i]=50;
            }
            else if(choice ==2){
                cus[i]="Creamy topping";
                price[i]=150;
            }
            else if(choice ==3){
                cus[i]="Both";
                price[i]=200;
            }
            else{
                cus[i]="No Customization";
                price[i]=0;
            }
        }
        else if(Final_Array[i].category=="Desserts"){
            cout << "\n\t\tFOR DESSERTS!!!" << endl;
            cout << "1. Caramel Topping\t Rs.100/-\n2. Chocolate Topping\t Rs.80/-\n";
            cout << "----------------------------------------------";
			cout << "\nPress any other key for No Customization" << endl;
			cout << "----------------------------------------------" << endl;
            cout << "\n\n Enter Your Choice :\t";
            cin >> choice;
            if(choice==1){
                cus[i]="Caramel Topping";
                price[i]=100;
            }
            else if(choice ==2){
                cus[i]="Chocolate Topping";
                price[i]=80;
            }
            else{
                cus[i]="No Customization";
                price[i]=0;
            }
        }
        else{
            cout << "No customization available for category " << Final_Array[i].category << endl;
            price[i]=0;
            cus[i]="No Customization";
        }
        }
    cout << "\n\nPress any key to generate your bill." << endl;
    getch();
    return price;
}
