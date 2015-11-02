#pragma once

#ifndef SOLUTIONS_CHAPYGIN_SRC_DIV_H_
#define SOLUTIONS_CHAPYGIN_SRC_DIV_H_

#define MAX_LEN 300

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Trying to divide %lf by %lf", a, b);
    throw DivisionByZeroExcp(log, NULL);
  } else {
    return a / b;
  }
}

#endif  // SOLUTIONS_CHAPYGIN_SRC_DIV_H_
