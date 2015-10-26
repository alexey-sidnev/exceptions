#pragma once

#ifndef SOLUTIONS_BASE_VERSION_SRC_MYEXCEPTION_H_
#define SOLUTIONS_BASE_VERSION_SRC_MYEXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;


class MyException {
protected:
	MyException *e;
	char* str;
public:
	void WriteLog();
	virtual ~MyException();
	MyException(){};
	MyException(char*str0, MyException*e0);
	MyException(const MyException&E);
};

class Exception1 : public MyException{
private:

public:
	Exception1(char*str1, MyException *e1) : MyException(str1, e1){}
	Exception1(const MyException &E) :MyException(E){}
};

class Exception2 : public MyException{
private:

public:
	Exception2(char*str1, MyException *e1) : MyException(str1, e1){}
	Exception2(const MyException &E) :MyException(E){}
};

class Exception3 : public MyException{
private:

public:
	Exception3(char*str1, MyException *e1) : MyException(str1, e1){}
	Exception3(const MyException &E) :MyException(E){}
};

class Exception4 : public MyException{
private:

public:
	Exception4(char*str1, MyException *e1) : MyException(str1, e1){}
	Exception4(const MyException &E) :MyException(E){}
};


#endif  // SOLUTIONS_BASE_VERSION_SRC_MYEXCEPTION_H_
