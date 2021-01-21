#include "Queue.h"
#include <iostream>

void gotoxy(int x,int y){	
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}
Production::  Production( ){
	this->Production_Name = "" ;
	this->Word = "" ;
	this->Type = "" ;
	}

Queue:: Queue( int Size_ = 10 ){
	this->Data = new Production[Size_];
	this->Size = Size_ ;
	this->Front = -1 ;
	this->Rear = -1 ;

}
void Queue:: Enqueue( string _Production_Name , string _Word , string _Type )
{
	Production Data_ ;
	Data_.Production_Name = _Production_Name ;
	Data_.Type = _Type ;
	Data_.Word = _Word ;
	if( ( this->Rear + 1 ) % this->Size == this->Front )
	{
		cout<<"\nException Thrown : Queue Is Already Full !\n" ;
	}
	else
	{
        this->Rear = ( ( this->Rear + 1 ) % ( this->Size ) ) ;
        this->Data[this->Rear] = Data_ ;
        if( this->Front == -1 )
        {
            this->Front = 0 ;
        }
	}
}
		
Production Queue::Dequeue_From_Front(){
	if( this->Rear == this->Front  ){
		cout<<"\nException Thrown : Queue Is Empty !\n" ;
        exit(1) ;
	}
	else{
        Production Temp = this->Data[ this->Front ] ;
		this->Front = ( ( this->Front + 1 ) % ( this->Size ) ) ;
        return Temp ;
	}
}

void Queue:: Dequeue_From_Rear(){
    if( this->Rear != -1 ){
        this->Rear--;
    }
}

Production Queue:: Peek(){
	return this->Data[ this->Front ] ;
}
		
void Queue:: Print_Queue(){	
	system("cls");
   	gotoxy(33,2);
	for(int i=0;i<59;i++){
		cout << "\xB2";
	}
		gotoxy(33,25);
	for(int i=0;i<59;i++){
		cout << "\xB2";
	}
	gotoxy(50,3);
	cout<<"VALID STRUCTURE";
	string Output = "" ;
	gotoxy(34,5);
	cout<<"S\n" ;
	int i = this->Front ;
    while(i!=this->Rear){
		if( Output == "" && this->Data[i].Type == "DETERMINER" ){
			while( this->Data[i+1].Production_Name == "NOMINAL" ){
				cout<<"\t\t\t\t "<<Output<<" "<<this->Data[i].Production_Name<<" VP"<<endl
		           <<"\t\t\t\t " <<Output<<" "<<this->Data[i].Type<<" VP"<<endl ;
			    Output = Output + " " + this->Data[i].Word ;
			    ++i ;
			}
		}
		else if( Output == "" ){
			cout<<"\t\t\t\t "<<Output<<" "<<this->Data[i].Production_Name<<" VP"<<endl
		    <<"\t\t\t\t "<<Output<<" "<<this->Data[i].Type<<" VP"<<endl ;
		}
		else{
			cout<<"\t\t\t\t "<<Output<<" "<<this->Data[i].Production_Name<<endl
		   <<"\t\t\t\t " <<Output<<" "<<this->Data[i].Type<<" "<<this->Data[i+1].Production_Name<<endl ;
		}

		Output = Output + " " + this->Data[i].Word ;
		++i ;
	}
		cout<<"\t\t\t\t "<<Output<<" "<<this->Data[i].Production_Name<<endl
		<<"\t\t\t\t "<<Output<<" "<<this->Data[i].Type<<endl ;
		Output = Output + " " + this->Data[i].Word ;
		cout<<"\t\t\t\t "<<Output<<endl ;
}
