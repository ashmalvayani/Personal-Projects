#include "MyException.h"

MyException:: MyException(int index){
	this->index=index;
}

const char* MyException:: what() const throw(){
	return "The option number is invalid!";
}
