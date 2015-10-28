#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

#ifndef SOLUTIONS_ZHORIN_SRC_MYEXCEPTION_H_
#define SOLUTIONS_ZHORIN_SRC_MYEXCEPTION_H_

class MyException {
 protected:
  MyException *prev;
  char* Log;
 public:
  void WriteLog();
  virtual ~MyException();
  MyException() {}
  MyException(char*, MyException*);
  MyException(const MyException&);
};
class DivByZero : public MyException {
 public:
  DivByZero(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1)
  {}
};
class NoMemory : public MyException {
 public:
  NoMemory(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1)
  {}
};
class ExcpForTest3 : public MyException {
 public:
  ExcpForTest3(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1)
  {}
};
class ExcpForTest4 : public MyException {
 public:
  ExcpForTest4(char*Log_1, MyException *prev_1) : MyException(Log_1, prev_1)
  {}
};
#endif  // SOLUTIONS_ZHORIN_SRC_MYEXCEPTION_H_
