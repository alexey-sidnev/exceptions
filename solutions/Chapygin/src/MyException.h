#pragma once

#ifndef SOLUTIONS_CHAPYGIN_SRC_EXCEPTIONS_H_
#define SOLUTIONS_CHAPYGIN_SRC_EXCEPTIONS_H_

#include <iostream>
#include <string>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

#define MAX_LEN 300

class MyException {
 public:
  char* errLog;
  MyException* prevEx;
  MyException();
  MyException(char* _errLog, MyException* _prevEx);
  MyException(const MyException& excp);
  virtual ~MyException();
  virtual void WriteLog();
};

class DivisionByZeroExcp : public MyException {
 public:
  DivisionByZeroExcp(char* _errLog, MyException* _prevEx)
  : MyException(_errLog, _prevEx) {}
  explicit DivisionByZeroExcp(const MyException &excp)
  : MyException(excp) {}
};

class AllocationExcp :public MyException {
 public:
  AllocationExcp(char* _errLog, MyException* _prevEx)
  : MyException(_errLog, _prevEx) {}
  explicit AllocationExcp(const MyException &excp)
  : MyException(excp) {}
};
class CastExcp : public MyException
{
 public:
  CastExcp(char* _errLog, MyException* _prevEx)
  : MyException(_errLog, _prevEx) {}
  explicit CastExcp(const MyException &excp)
  : MyException(excp) {}
};
class SumExcp : public MyException {
 public:
  SumExcp(char* _errLog, MyException* _prevEx)
  : MyException(_errLog, _prevEx) {}
  explicit SumExcp(const MyException &excp)
  : MyException(excp) {}
};

#endif  // SOLUTIONS_CHAPYGIN_SRC_EXCEPTIONS_H_
