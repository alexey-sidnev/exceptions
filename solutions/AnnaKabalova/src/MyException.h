#pragma once
#include "string.h"
#include "stdio.h"
#ifndef SOLUTIONS_ANNAKABALOVA_SRC_MYEXCEPTION_H_
#define SOLUTIONS_ANNAKABALOVA_SRC_MYEXCEPTION_H_
class MyException {
 public:
  char *str;
  MyException* exc;
  MyException(char *_str, MyException*ex);
  MyException(const MyException&ex);
  ~MyException();
  virtual void WriteLog();
};

class divZero :public MyException {
 public:
  divZero(char *_str, MyException*ex) :MyException(_str, ex)
  {}
};
class NoMem :public MyException {
 public:
  NoMem(char *_str, MyException *ex) :MyException(_str, ex)
  {}
};
class DynExc :public MyException {
 public:
  DynExc(char *_str, MyException*ex) :MyException(_str, ex)
  {}
};
class SumExc :public MyException {
 public:
  SumExc(char *_str, MyException*ex) :MyException(_str, ex)
  {}
};

#endif  // SOLUTIONS_ANNAKABALOVA_SRC_MYEXCEPTION_H_
