
#pragma once
#ifndef SOLUTIONS_KIPARENKOIV_SRC_DIV_H_
#define SOLUTIONS_KIPARENKOIV_SRC_DIV_H_

#include "MyException.h"

template <class T>
T MyDiv(T a, T b) {
  if(b == 0) {
    char *r = new char[90];
    sprintf_s(r, 90, "MyDiv with arguments (a=%lf) and (b=%lf)", a, b);
    throw DivByZeroException(r);
  }
  return a / b;
}

#endif  // SOLUTIONS_KIPARENKOIV_SRC_DIV_H_
