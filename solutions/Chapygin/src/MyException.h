#pragma once

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#define _CRT_SECURE_NO_WARNINGS


#define MAX_LEN 100

class MyException {
 protected:
  char errorMessage[MAX_LEN];
  char errorPosition[MAX_LEN];
  MyException* prevEx;
 public:
  MyException();
  MyException(char* _errorMessage, char* _errorPosition, MyException* _prevEx);
  MyException(const MyException& excp);
  virtual ~MyException();
  virtual void WriteLog();
};

class DivisionByZeroExcp :public MyException
{
 public:
  DivisionByZeroExcp(char* _errorPosition, MyException* _prevEx) :MyException("Division by zero :(", _errorPosition, _prevEx){}
};

class AllocationExcp :public MyException
{
 public:
  AllocationExcp(char* _errorPosition, MyException* _prevEx) :MyException("Bad allocation :(", _errorPosition, _prevEx){}
};
class CastExcp :public MyException
{
 public:
  CastExcp(char* _errorPosition, MyException* _prevEx) :MyException("Bad cast :(", _errorPosition, _prevEx){}
};
class SumExcp :public MyException
{
 public:
  SumExcp(char* _errorPosition, MyException* _prevEx) :MyException("Bad sum :(", _errorPosition, _prevEx){}
};

#endif  // EXCEPTIONS_H