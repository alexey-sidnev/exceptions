#pragma once

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class MyException {
protected :
    char *str;
    MyException *ex;
public :
    MyException(){}
    MyException(char *str1, MyException *ex1);
    MyException(const MyException &EX);
    void WriteLog();
    virtual ~MyException();
                  };

class test1 : public MyException {
public :
    test1(char *str_1, MyException *ex_1) : MyException(str_1, ex_1){}
    test1(const MyException &EX) : MyException(EX) {}
                                 };

class test2 : public MyException {
public :
    test2(char *str_2, MyException *ex_2) : MyException(str_2, ex_2){}
    test2(const MyException &EX) : MyException(EX) {};
                                 };

class test3 : public MyException {
public :
    test3(char *str_3, MyException *ex_3) : MyException(str_3, ex_3){}
    test3(const MyException &EX) : MyException(EX) {};
                                 };

class test4 : public MyException {
public :
    test4(char *str_4, MyException *ex_4) : MyException(str_4, ex_4){}
    test4(const MyException &EX) : MyException(EX) {};
                                 };

#endif  // SOLUTIONS_PETROVA_SRC_MYEXCEPTION_H_"
