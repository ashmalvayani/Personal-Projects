#include "Customer.h"

Customer:: Customer(){
    cus_name=0;
    email=0;
    address=0;
    phone=0;
    password=0;
    code=0;
    validity=false;
}
Customer:: Customer(char* cus_name, char* email, char* address, char* phone, char* password,char* code){
    this->cus_name = cus_name;
    this->email = email;
    this->address = address;
    this->phone = phone;
    this->password = password;
    this->code = code;
}
char* Customer:: getemail() const{
	return email;
}
char* Customer:: getpass() const{
    return password;
}
char* Customer:: getname() const{
	return cus_name;
}
char* Customer:: getcode() const{
    return code;
}
void Customer ::  Sign_Up(){
	char* cus_name= new char[20];
	char* email= new char[20];
	char* address = new char[20];
	char* phone= new char[20];
	char* password = new char[20];
	char* code= new char[20];
    int k, count=0;
    char z;
    system("cls");
    cout << "\t\t\t***SIGN UP***" << endl;
    cout << "Enter Your information to Sign up.\n\n1. Enter your Name:\t\t\t ";
	fflush(stdin);
	gets(cus_name);
    
   do{
       cout << "2. Enter your Email Address: \t\t ";
       fflush(stdin);
    	gets(email);
       if(DeliveryServices:: Email_check(email)){
            break;
       }
       else{
           cout << "Invalid Email Address. Please enter again.\n";
       }
   }while(true);

    cout << "3. Enter your residential Address: \t ";
    fflush(stdin);
    gets(address);
    cout << "4. Enter your PhoneNumber(03xx-xxxxxxx): ";
    phone = DeliveryServices:: check_phone();
  
    cout << "5. Enter Password: \t\t\t ";
	password = DeliveryServices:: mask_password();
	
    cout << "\n\nDo you want a Premium Membership?\nEnter 'Y' to avail the premium membership.\nOr Press any key to continue ... \t";
    cin >> z;
    if(z == 'Y' || z == 'y')
    {
    	bool check= true;
    	cout << "\nPackages Available:\n1)\t10% off\tRs.500\n2)\t20% off\tRs.900\n3)\t30% off\tRs.1500\nEnter your choice (1-3) :\t";
        do{
        	check=true;
	        cin >> k;
	        if(k==1)
	            code="PREMIUM10";
	        else if(k==2)
	            code="PREMIUM20";
	        else if(k==3)
	            code="PREMIUM30";
	        else{
	        	check=false;
	        	cout << "\nInvalid Choice. Please re-enter :\t";
			}
	        	
		}while(check==false);
        
        cout << "\n------------------------------------------------------------------------------------";
        cout << " \n   The Amount will be added to your next bill. This membership expires by 31/12/21." << endl;
        cout << "------------------------------------------------------------------------------------";
    }
    else
        code = "NO";
    
    Customer cs(cus_name, email, address, phone, password, code);
    ofstream ob("Customer.txt", ios::app);
    ob.write((char*)&cs, sizeof(cs));
    ob.close();
}

// to check from main if information is correct otherwise don't proceed.
Customer Customer:: Log_In(){
    char* a= new char[20];
    char* b= new char[20];
    int k=0, check, z=0;
    bool l=false;
    
    do{
        z=0;
        cout << "\n1. If you're Manager" << endl << "2. If you're Customer" << endl;
        cout << "\nEnter your choice:\t";
        cin >> check;
        if(check==1){
            char* code= new char[10];
            cout << "\nEnter your Manager Code (For now you can use 'abc123') :\t";
            cin >> code;
            if(strcmp(code,"abc123")==0){
                DeliveryServices:: Manager_Portal();
                Customer c2;
                c2.setcode(0);
                return c2;
            }
            else {
                cout << "Code does not match, Please enter again." << endl;
                z=1;
            }
        }
        else if (check==2){
        	cout<< "\n--------------------------------------------------------";
            cout << "\nEnter User information to Login.\n\nEnter Email ID:\t";
             fflush(stdin);
   			 gets(a);
            
            Customer C, C2;
            ifstream ob("Customer.txt");
            if(!ob){
            	cout << "\nCustomer Information not found, please Sign-Up first!";
				return C2;
			}
            ob.read((char*)&C, sizeof(C));
            while(!ob.eof()){
            	if(strcmp(C.getemail(),a)==0){
            		k=1;
            		break;
				}
				ob.read((char*)&C, sizeof(C));
			}
			ob.close();
			if (k==0){
				cout << "\nCustomer Information not found, please Sign-Up first!";
				return C2;
			}
            k=0;
            cout << "Enter Password:\t";
			b= DeliveryServices::mask_password();
			
            ob.open("Customer.txt");
            ob.read((char*)&C, sizeof(C));
                
            while(!ob.eof()){
                if(strcmp(C.getpass(),b)==0){
                    cout << "\n\nLOGIN SUCCESSFULL!";
                    C2=C;
                    k=1;
                }
                ob.read((char*)&C, sizeof(C));
        	}
            if (k==0){
            	cout << "\nInvalid Password, Please try coming back again!";
            	C2.setValidity(false); // to check if information is valid or not
			}
			else
			C2.setValidity(true); // to check if information is valid or not
                
            ob.close();
            
            return C2;
        }
        else{
            cout <<"Invalid Entry. Please enter again." << endl << endl;
            z=1;
        }
    }while(z==1);
}

void Customer:: setcode(char* a){
	code=a;
}

bool Customer:: getValidity(){
	return validity;
}

void Customer:: setValidity(bool v){
	validity=v;
}
