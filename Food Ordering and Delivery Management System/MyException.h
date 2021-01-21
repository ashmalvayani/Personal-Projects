#include <iostream>
#include <exception>
using namespace std;

#ifndef MyException_H      // header guard
#define MyException_H      // to avoid duplication


class MyException: public exception{
 private:
 	int index;
 public:
		MyException(int);						// constructor
		const char* what() const throw();		// over-riding the constant functions
};

#endif
