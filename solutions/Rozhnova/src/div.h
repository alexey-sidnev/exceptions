#pragma once
#ifndef SOLUTIONS_ROZHNOVA_SRC_DIV_H_
#define SOLUTIONS_ROZHNOVA_SRC_DIV_H_

template <class T>
T MyDiv(T a, T b) {
  if (b == 0) {
  char *st = new char[300];
  sprintf_s(st, 300, "MyDiv parem: a=%lf b=%lf", a, b);
  throw divZero(st, 0);
  } else {
    return a / b;
  }
}

#endif  // SOLUTIONS_ROZHNOVA_SRC_DIV_H_
