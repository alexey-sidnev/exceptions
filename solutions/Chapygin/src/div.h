#pragma once
#ifndef SOLUTIONS_CHAPYGIN_SRC_DIV_H_
#define SOLUTIONS_CHAPYGIN_SRC_DIV_H_

#define MAX_LEN 100

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
    char* temp = new char[MAX_LEN];
    sprintf_s(temp, "Test 2, MyDiv(%f,%f)", a, b);
    throw DivisionByZeroExcp(temp, NULL);
  }
  return a / b;
}

#endif  // SOLUTIONS_CHAPYGIN_SRC_DIV_H_
