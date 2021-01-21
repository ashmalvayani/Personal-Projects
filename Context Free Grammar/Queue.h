#ifndef QUEUE_H
#define QUEUE_h

#pragma once

#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std ;

class Production
{
	public :
	string Production_Name ;
	string Word ;
	string Type ;
    Production( );
};

class Queue
{
	private:
		int Size ;
		int Front ;
		int Rear ;
        Production *Data ;
	public:
		Queue( int );
		void Enqueue( string  , string , string );
		Production Dequeue_From_Front();
        void Dequeue_From_Rear();
		Production Peek();
		void Print_Queue( );
};

#endif
