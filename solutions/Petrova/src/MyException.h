#pragma once

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
using namespace std;

class MyException {
protected:
	char *str;
	MyException *ex;
public:
	MyException(){};
	MyException(char *str1, MyException *ex1);
	MyException(const MyException &EX);
	void WriteLog();
	//virtual ~MyException(){};
 };

class test1 : public MyException
{
public:
	test1():MyException(){};
	test1(char *str_1, MyException *ex_1);
	test1(const test1 &EX);
	//virtual ~test1(){};
};

class test2 : public MyException
{
public:
	test2():MyException(){};
	test2(char* str_2, MyException *ex_2);
	test2(const test2 &EX);
	//virtual ~test2(){};
};

class test3 : public MyException
{
public:
	test3():MyException(){};
	test3(char* str_3, MyException *ex_3);
	test3(const test2 &EX);
	//virtual ~test3(){};
};

#endif  // EXCEPTIONS_H
