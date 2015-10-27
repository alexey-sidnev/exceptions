#pragma once
#ifndef SOLUTIONS_ZHORIN_SRC_DIV_H_
#define SOLUTIONS_ZHORIN_SRC_DIV_H_
#include "locale.h"
#include "MyException.h"

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
    char*Log1 = new char[300];
    sprintf_s(Log1, 300, "Division by zero, arguments:(a=%lf) and (b=%lf)", a, b);
    throw DivByZero(Log1, 0);
  }
  return a / b;
}

#endif  // SOLUTIONS_ZHORIN_SRC_DIV_H_
