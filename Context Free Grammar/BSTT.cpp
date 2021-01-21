#include "BST.h"
#include "MenuDriven.h"
#include "MenuDriven.cpp"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

Student_Node:: Student_Node(){}

Student_Node:: Student_Node(string Name, int Age, string ID, string Email, string Password){
    this->Student_Name = Name;
    this->Student_Age = Age;
    this->Student_ID = ID;
    this->Student_Email = Email;
    this->Student_Password = Password;
    this->leftchild = this->rightchild = NULL;
}

Student_Node& Student_Node:: operator=(Student_Node &rhs){
    if(this!=&rhs){
        this->Student_Name = rhs.Student_Name;
        this->Student_ID = rhs.Student_ID;
        this->Student_Email = rhs.Student_Email;
        this->Student_Password = rhs.Student_Password;
        this->Student_Age = rhs.Student_Age;
    }
    return(*this);
}

BinarySearchTree:: BinarySearchTree(){
    root = NULL;
}
void BinarySearchTree:: AddNewRecord(string Name, int Age, string ID, string Email, string Password){
    Student_Node *p = root, *r;
    Student_Node *temp;
    if(!root){
        temp = new Student_Node(Name,Age,ID,Email,Password);
        root = temp;
        writeToFile(root);
        return;
    }
    while(p){
        r = p;
        if(strcmp(ID.c_str(), p->Student_ID.c_str())==0)
            return;
        if(strcmp(ID.c_str(), p->Student_ID.c_str())==1)
            p = p->rightchild;
        else
            p = p->leftchild;
    }
    temp = new Student_Node(Name,Age,ID,Email,Password);
    if(strcmp(ID.c_str(), r->Student_ID.c_str())==1)
        r->rightchild = temp;
    else 
        r->leftchild = temp;

    
    writeToFile(temp);
}

void BinarySearchTree:: writeToFile(Student_Node *temp){
    ofstream fileptr("StudentsRecords.txt", ios::app);
    if(!fileptr){
        cout << "Can't open file.\n";
        exit(0);
    }
    string Output = "";
    Output = temp->Student_Name + " " + temp->Student_ID + " " + to_string(temp->Student_Age) + " " + temp->Student_Email + " " + temp->Student_Password;
    fileptr << Output << endl;
    fileptr.close();
}
void BinarySearchTree:: InOrderTraversalWrapper(){
    InOrderTraversal(root);
}
void BinarySearchTree:: InOrderTraversal(Student_Node* ptr){
    if (ptr){
        PreOrderTraversal(ptr->leftchild);
        Display(ptr);
        PreOrderTraversal(ptr->rightchild);
    }    
}
void BinarySearchTree:: PreOrderTraversalWrapper(){
    PreOrderTraversal(root);
}
void BinarySearchTree:: PreOrderTraversal(Student_Node* ptr){
    if (ptr){
        Display(ptr);
        PreOrderTraversal(ptr->leftchild);
        PreOrderTraversal(ptr->rightchild);
    }    
}

void BinarySearchTree:: Display(Student_Node* node){
    cout << "STUDENT INFORMATION!\n";
    cout<< "Student Name : " << node->Student_Name << endl
        << "Student Age  : " << node->Student_Age << endl
        << "Student ID   : " << node->Student_ID << endl
        << "Student Email: " << node->Student_Email << endl;
}

int BinarySearchTree:: HeightWrapper(){
    return Height(root);
}
int BinarySearchTree:: Height(Student_Node* ptr){
    int x=0, y=0;
    if(!ptr)
        return 0;
    x = Height(ptr->leftchild);
    y = Height(ptr->rightchild);
    return x>y ? x+1: y+1;
}


Student_Node* BinarySearchTree:: Search(string ID){
    Student_Node* temp = root;
    while(temp){
        if(strcmp(temp->Student_ID.c_str(),ID.c_str())==0)
            return temp;
        else if(strcmp(ID.c_str(),temp->Student_ID.c_str())==-1)
            temp = temp->leftchild;
        else
            temp = temp->rightchild;
    }
    return NULL;
}

Student_Node* BinarySearchTree::  DeleteWrapper(string key){
    DeleteNode(root,key);
}
Student_Node* BinarySearchTree:: DeleteNode(Student_Node* node, string ID){

    if(!node)
        return NULL;
    if(!node->leftchild && !node->rightchild){
        if(node==root)
            root = NULL;
        delete node;
        return NULL;
    }

    if(strcmp(ID.c_str(), node->Student_ID.c_str())==1)
        node->rightchild = DeleteNode(node->rightchild, ID);
    else if(strcmp(ID.c_str(),node->Student_ID.c_str())==-1)
        node->leftchild = DeleteNode(node->leftchild,ID);
    else{
        Student_Node *temp;
        if(Height(node->leftchild)> Height(node->rightchild)){
            temp = InorderPredecessor(node->leftchild);
            node = temp;
            node->leftchild = DeleteNode(node->leftchild, temp->Student_ID);
        }
        else{
            temp = InorderSuccessor(node->rightchild);
            node = temp;
            node->rightchild = DeleteNode(node->rightchild, temp->Student_ID);
        }
    }
    return node;
}

Student_Node* BinarySearchTree:: InorderPredecessor(Student_Node *ptr){
    while(!ptr && !ptr->rightchild)
        ptr = ptr->rightchild;
    return ptr;
}

Student_Node* BinarySearchTree:: InorderSuccessor(Student_Node *ptr){
    while(!ptr && !ptr->leftchild)
        ptr = ptr->leftchild;
    return ptr;
}


bool BinarySearchTree:: Login(){
    string email, password;

    ifstream infile("StudentsRecords.txt", ios:: in);
    if(!infile){
        cout << "There are currently no registered acconts, please sign up first.\n";
        return false;
    }

    do{
        cout << "Enter your Email Address : ";
        cin >> email;
        if(!MenuDriven::Email_check(email)){
            cout << "Invalid Email Address. Try again.\n";
        }
    }while(!MenuDriven::Email_check(email));

    string input_record;
    while(!infile.eof()){
        getline(infile,input_record);

        string *token = ParseWords(input_record);
        
        if(email==token[3]){
            cout << "Enter your password :\t   ";
            password = MenuDriven::mask_password();
            if(strcmp(password.c_str(),token[4].c_str())==0){
                cout << "Email and password matched.\n";
                cout << "Press any key to continue.\n";
                getch();
                infile.close();
                return true;
            }
            else{
                cout << "password didn't matched.\n";
            }
        }
    }

    infile.close();
    return false;
}

string* BinarySearchTree:: ParseWords(string input_record){
    static string token[5];
    string delimitter = " ";
    size_t pos = 0;

    int i = 0;
    while((pos = input_record.find(delimitter))!=string::npos){
        token[i++] = input_record.substr(0,pos);
        input_record.erase(0,pos+delimitter.length());
    }
    token[i] = input_record.substr(0,pos);

    return token;
}

void BinarySearchTree:: SignUp(){
    string name, S_ID, email, password;
    int age;

    cout << "1. Enter your Name :\t\t";
    cin >> name;
   
    while(true){
        cout << "2. Enter your Age  : \t\t";
        cin >> age;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\tInvalid age please re-enter\n";
        }
        else
            break;   
    }
    cout << "3. Enter your Student ID :\t";
    cin >> S_ID;
    do{
        cout << "4. Enter your Email Address :\t";
        cin >> email;
        if(!MenuDriven::Email_check(email)){
            cout << "\tInvalid Email Address. Try again.\n";
        }
    }while(!MenuDriven::Email_check(email));


    ifstream outline("StudentsRecords.txt",ios::in);
    if(outline){
        string record, *token;
        
        while(!outline.eof()){
            getline(outline,record);
            token = ParseWords(record);
            if(token[3]==email){
                cout << "Student record already exists.\n";
                outline.close();
                return;
            }
        }
    }   
    outline.close();
    cout << "5. Enter your password :\t";
    password = MenuDriven::mask_password();

    AddNewRecord(name,age,S_ID,email,password);
}
