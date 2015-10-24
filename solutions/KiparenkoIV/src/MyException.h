#pragma once

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

static  char* errorsT[4]={"DivByZero","BadAlloc","BadDynamicCast","Transport"};

class MyException {
 public:
  char* system;
  MyException* ex; 
  int errType;
  //MyException(int err, char* sys=0);
  MyException(int err=0, char* sys=0,MyException* e=0);
  MyException(MyException & e);
  ~MyException();
  void WriteLog();
};

class DivByZeroException :public MyException
{
 public:
  DivByZeroException(char* sys,MyException* e=0):MyException(0, sys,e){}
};

class BadAllocException :public MyException
{
 public:
  BadAllocException(char* sys,MyException* e=0):MyException(1, sys,e){}
};

class BadDynamicCastException :public MyException
{
 public:
  BadDynamicCastException(char* sys,MyException* e=0):MyException(2, sys,e){}
};

class ContainException :public MyException
{
 public:
  ContainException(char* sys,MyException* e=0):MyException(3, sys,e){}
};



#endif  // EXCEPTIONS_H
