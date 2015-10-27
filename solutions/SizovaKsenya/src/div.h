#pragma once

#ifndef SOLUTIONS_SIZOVAKSENYA_SRC_DIV_H_
#define SOLUTIONS_SIZOVAKSENYA_SRC_DIV_H_
#define m 100

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
    char *s = new char[m];
    sprintf_s(s, m, "Exception DivisionByZero: MyDiv with arguments (a=%lf) and (b=%lf)", a, b); 
    throw Exception2(s, 0);
  } 
  else
    return a / b;
}

#endif  // SOLUTIONS_BASE_VERSION_SRC_DIV_H_
