#pragma once
#include "string.h"
#include "stdio.h"
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#define _CRT_SECURE_NO_WARNINGS
class MyException {
public:
	char *str;
	MyException* exc;
	MyException(char *_str, MyException*ex);
	MyException(MyException&ex);
	~MyException();
	virtual void WriteLog();
};


class divZero :public MyException
{
public:
	divZero(char *_str, MyException*ex) :MyException(_str, ex)
	{}
};
class NoMem :public MyException
{
public:
	NoMem(char *_str, MyException *ex) :MyException(_str, ex)
	{}
};
class DynExc :public MyException
{
public:
	DynExc(char *_str, MyException*ex) :MyException(_str, ex)
	{}
};
class SumExc :public MyException
{
public:
	SumExc(char *_str, MyException*ex) :MyException(_str, ex)
	{}
};

#endif  // EXCEPTIONS_H
