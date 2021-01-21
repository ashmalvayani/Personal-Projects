#ifndef CONTEXT_FREE_GRAMMAR_h
#define CONTEXT_FREE_GRAMMAR_h

#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include "Queue.h"
using namespace std;

class Word_Node{
public :
    string Word ;
    string Type ;
    Word_Node();
    Word_Node(string,string);
};

class Context_Free_Grammar{
private:
	Word_Node *Sentence ;
    int Sentence_Length ;
public :
    Context_Free_Grammar();
    void Start_Program();
    
    bool Check_If_True(int&);
    string Find_Type(string&);
    void Assign_Types();
    int Total_Words(string);
    void To_Upper_Case(string &);
    int Check_Sentence_Structure_For_Nominal( int , Queue&);
    int Check_Sentence_Structure_For_NP( int , Queue&);
    int Check_Sentence_Structure_For_PP( int , Queue&);
    int Check_Sentence_Structure_For_VP( int , Queue&);
    
    ~Context_Free_Grammar();
};

#endif
