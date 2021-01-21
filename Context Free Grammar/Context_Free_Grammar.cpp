#include "Context_Free_Grammar.h"
#include <iostream>
using namespace std;

Word_Node:: Word_Node( string _Word , string _Type ){
    Word = _Word ;
    Type = _Type ;
}

Word_Node:: Word_Node(){}

Context_Free_Grammar :: Context_Free_Grammar(){}

void Context_Free_Grammar:: Start_Program(){
	string _Sentence ;
    fflush(stdin);
    getline( cin , _Sentence ) ;
    this->Sentence_Length = Total_Words(_Sentence) + 1 ;
    char TokenString[this->Sentence_Length * 20];
   
    strcpy( TokenString , _Sentence.c_str()) ;
    char *Token = strtok( TokenString , " ");
    this->Sentence = new Word_Node[this->Sentence_Length];
    int i = 0 ;
    while (Token != NULL){
        this->Sentence[i].Word = Token ;
        Token = strtok(NULL, " ");
		i++ ;
	}
    
    this->Assign_Types() ;
    cout<<endl ;
    
	Queue Track_Of_Production( this->Sentence_Length ) ;
    i = 0 ;
    i = this->Check_Sentence_Structure_For_NP( i , Track_Of_Production ) ;
    if( Check_If_True(i)){
        i = this->Check_Sentence_Structure_For_VP( i , Track_Of_Production ) ;
    }
    if( Check_If_True(i)){
        i = this->Check_Sentence_Structure_For_PP( i , Track_Of_Production ) ;
    }
    if( Check_If_True(i)){
        i = this->Check_Sentence_Structure_For_Nominal( i , Track_Of_Production ) ;
    }
    
	Track_Of_Production.Print_Queue() ;
}

bool Context_Free_Grammar:: Check_If_True( int &i ){
    if( i < 0 ){
    	system("cls") ;
    	   	gotoxy(33,5);
		for(int i=0;i<59;i++)
			cout << "\xB2";
		
		gotoxy(33,11);
		for(int i=0;i<59;i++)
			cout << "\xB2";
		
    	gotoxy(50,8);
        cout<<"INVALID STRUCTURE"<<endl ;
        gotoxy(1,25);
		exit(1) ;
    }	
    i++ ;
    return true ;
}

string Context_Free_Grammar:: Find_Type( string &__Word ){
    fstream Reader ;
    string Word ;
    To_Upper_Case(__Word) ;
    string dirTextInclude = "text/";
    string File_Names[8] = { "Nouns.txt" , "Pronouns.txt" , "Verbs.txt" , "Propernouns.txt" , "Prepositions.txt" , "Adjectives.txt" , "Determiners.txt" , "Conjunctions.txt" } ;
    string Corpuses[8] = { "Noun" , "Pronoun" , "Verb" , "Propernoun" , "Preposition" , "Adjective" , "Determiner" , "Conjunction" } ;
    for( int i = 0 ; i < 8 ; ++i ){
        Reader.open( dirTextInclude + File_Names[i] , ios::in ) ;
        while( !Reader.eof()){
            getline(Reader , Word) ;
            To_Upper_Case(Word) ;
            if( Word == __Word){
                Reader.close() ;
                return Corpuses[i] ;
            }
        }
        Reader.close() ;
    }
    system("cls") ;
       	gotoxy(33,5);
		for(int i=0;i<59;i++)
			cout << "\xB2";
			gotoxy(33,11);
		for(int i=0;i<59;i++)
			cout << "\xB2";
			
    gotoxy(50,8);
    cout<< "INVALID WORD TYPE";
    gotoxy(1,25);
    exit(1) ;
}


void Context_Free_Grammar:: Assign_Types(){
    string __Type ;
    for( int i = 0 ; i < this->Sentence_Length ; ++i ){
        __Type = Find_Type( this->Sentence[i].Word ) ;
        To_Upper_Case(__Type) ;
        this->Sentence[i].Type = __Type ;
    }
}


int Context_Free_Grammar:: Check_Sentence_Structure_For_Nominal( int i , Queue &__Track_Of_Production ){
    if( i < this->Sentence_Length){
        string Nominal = "" ;
        if( this->Sentence[i].Type == "NOUN" ){
            Nominal += this->Sentence[i].Word ;
            Nominal += " " ;
            __Track_Of_Production.Enqueue("NOMINAL" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            i++ ;
            return Check_Sentence_Structure_For_Nominal( i , __Track_Of_Production ) ;
        }
    }
    if( this->Sentence[i-1].Type == "DETERMINER" && this->Sentence[i].Type != "NOUN")
        return -1 ;
    
    i-- ;
    return i ;
}

int Context_Free_Grammar:: Check_Sentence_Structure_For_NP( int i , Queue &__Track_Of_Production){
    if( i < this->Sentence_Length){
        string NP = "" ;
        if( this->Sentence[i].Type == "PRONOUN" || this->Sentence[i].Type == "PROPERNOUN"){
            NP += this->Sentence[i].Word ;
            NP += " " ;
            __Track_Of_Production.Enqueue("NP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            return i ;
        }
        if( this->Sentence[i].Type == "DETERMINER"){
            NP += this->Sentence[i].Word ;
            NP += " " ;
            __Track_Of_Production.Enqueue("NP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            i++ ;
            return Check_Sentence_Structure_For_Nominal( i , __Track_Of_Production ) ;
        }
        if( this->Sentence[i-1].Type == "PREPOSITION"){
                NP += this->Sentence[i].Word ;
                NP += " " ;
                __Track_Of_Production.Enqueue("NP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
                i++ ;
                return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
        }
    }
    return -1 ;
}


int Context_Free_Grammar :: Check_Sentence_Structure_For_PP( int i , Queue &__Track_Of_Production){
    if( i < this->Sentence_Length ){
        string PP = "" ;
        if( this->Sentence[i].Type == "PREPOSITION"){
            PP += this->Sentence[i].Word ;
            PP += " " ;
            __Track_Of_Production.Enqueue("PP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            i++ ;
            return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
        }
        return -1 ;
    }
    i-- ;
    return i ;
}


int Context_Free_Grammar:: Check_Sentence_Structure_For_VP( int i , Queue &__Track_Of_Production ){
    if( i < this->Sentence_Length){
        string VP = "" ;
        if( this->Sentence[i].Type == "VERB" && i == this->Sentence_Length - 1 ){
            VP += this->Sentence[i].Word ;
            VP += " " ;
            __Track_Of_Production.Enqueue("VP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            return i ;
        }

        if( this->Sentence[i].Type == "VERB" && this->Sentence[i+1].Type == "PREPOSITION"){
            VP += this->Sentence[i].Word ;
            VP += " " ;
            __Track_Of_Production.Enqueue("VP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            i++ ;
            return Check_Sentence_Structure_For_PP( i , __Track_Of_Production ) ;
        }

        if( this->Sentence[i].Type == "VERB" ){
            VP += this->Sentence[i].Word ;
            VP += " " ;
            __Track_Of_Production.Enqueue("VP" , this->Sentence[i].Word , this->Sentence[i].Type ) ;
            i++ ;
            return Check_Sentence_Structure_For_NP( i , __Track_Of_Production ) ;
        }
    }
    return -1 ;
}

Context_Free_Grammar:: ~Context_Free_Grammar(){
	if(this->Sentence)
    	delete[] this->Sentence ;
}


int Context_Free_Grammar :: Total_Words( string S ){
    int i = 0 , Count = 0 ;
    while( i < S.length() ){
        if(S[i] == ' '){
            Count++ ;
        }
        i++ ;
    }
    return Count ;
}

void Context_Free_Grammar :: To_Upper_Case( string &Word ){
    for( int i = 0 ; i < Word.length() ; ++i ){
        if( Word[i] >= 'a' && Word[i] <= 'z' ){
            Word[i] -= 32 ;
        }
    }
}
