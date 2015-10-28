#pragma once
#ifndef DIV_H
#define DIV_H
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
    char* temp = new char[MAX_LEN];
    sprintf(temp, "Test 2, MyDiv(%f,%f)", a, b);
    throw DivisionByZeroExcp(temp,0);
  }
  return a / b;
}

#endif  // DIV_H
