
#pragma once

#ifndef SOLUTIONS_KIPARENKOIV_SRC_EXCEPTION_H_
#define SOLUTIONS_KIPARENKOIV_SRC_EXCEPTION_H_

static  char* errorsT[4] =
              {"DivByZero", "BadAlloc", "BadDynamicCast", "Transport"};

class MyException {
 public:
  char* system;
  MyException* ex;
  int errType;
  // MyException(int err, char* sys=0);
  explicit MyException(int err = 0, char* sys = 0, MyException* e = 0);
  explicit MyException(MyException & e);
  ~MyException();
  void WriteLog();
};

class DivByZeroException :public MyException {
 public:
  explicit DivByZeroException(char* sys, MyException* e = 0):
                                      MyException(0, sys, e){}
};

class BadAllocException :public MyException {
 public:
  explicit BadAllocException(char* sys, MyException* e = 0):
                                     MyException(1, sys, e){}
};

class BadDynamicCastException :public MyException {
 public:
  explicit BadDynamicCastException(char* sys, MyException* e = 0):
                                           MyException(2, sys, e){}
};

class ContainException :public MyException {
 public:
  explicit ContainException(char* sys, MyException* e = 0):
                                    MyException(3, sys, e){}
};



#endif  // SOLUTIONS_KIPARENKOIV_SRC_EXCEPTION_H_
