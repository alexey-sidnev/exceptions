#pragma once
#include <iostream>

#include <stdio.h>
#include <string>

using namespace std;

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class MyException {
protected:
	MyException *prev;
	char* Log;
public:

	void WriteLog();
	virtual ~MyException();
	MyException(){};
	MyException(char*, MyException*);
	MyException(const MyException&);
};
class DivByZero : public MyException{
private:

public:
	DivByZero(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1){}
	DivByZero(const MyException &ex) :MyException(ex){}
};
class NoMemory : public MyException{
private:

public:
	NoMemory(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1){}
	NoMemory(const MyException &ex) :MyException(ex){}
};
class ExcpForTest3 : public MyException{
private:

public:
	ExcpForTest3(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1){}
	ExcpForTest3(const MyException &ex) :MyException(ex){}
};
class ExcpForTest4 : public MyException{
private:

public:
	ExcpForTest4(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1){}
	ExcpForTest4(const MyException &ex) :MyException(ex){}
};


#endif  // EXCEPTIONS_H
