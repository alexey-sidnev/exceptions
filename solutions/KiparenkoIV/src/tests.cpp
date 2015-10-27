#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string>
#include "generator.h"
#include "sort.h"
#include "div.h"
#include "classes.h"
#include "MyException.h"

#define EXP_TEST1_COUNT 10
#define EXP_TEST2_COUNT 1000

void Test1(unsigned int size) {
  double minTime = std::numeric_limits<double>::max(),
    maxTime = 0.,
    avgTime = 0.;
  double *mas = 0;

  try {
    mas = new double[size];
  }
  catch(...) {
    char *r = new char[90];
    sprintf_s(r, 90, "Test1 with argument (size=%i)", size);
    throw BadAllocException(r, 0);
  }
  for (int i = 0; i < EXP_TEST1_COUNT; i++) {
    double time;
    InitRandPositiveDouble(mas, size);
    time = Sort(mas, size);
    if (time < minTime) minTime = time;
    if (time > maxTime) maxTime = time;
    avgTime += time;
  }

  avgTime /= EXP_TEST1_COUNT;
  printf("Test1 (%i) passed:\n\tmin=%lf, max=%lf, avg=%lf\n", size,
    minTime, maxTime, avgTime);
  delete[] mas;
}

void Test2() {
  for (int i = 0; i < EXP_TEST2_COUNT; i++) {
    long double x = rand();
    long double y = rand();
    try {
      MyDiv(x, y);
    }
    catch (MyException& e) {
      char *r = new char[90];
      sprintf_s(r, 90, "Test2 with no arguments with call another function");
      throw ContainException(r, new MyException(e));
    }
  }
  printf("Test2 passed.\n");
}

void Test3(A *b) {
  try {
    if (dynamic_cast<B&>(*b).member()) {
      printf("Class A\n");
    } else {
      printf("Class B\n");
    }
  }
  catch (...) {
    char *r = new char[50];
    char e = (b->member())?'B':'A';
    sprintf_s(r, 50, "Test3 with argument (b=%c)", e);
    throw BadDynamicCastException(r, 0);
  }
  printf("Test3 passed.\n");
}

double Sum(long double n) {
  if (n < 0) return 0.;
  if (n == 0. || n == -0.) {
    char *r = new char[60];
    sprintf_s(r, 60, "Sum with argument (n=%lf)", n);
    throw DivByZeroException(r);
  }
  try {
    return 1./n + Sum(n - 1);
  }
  catch (MyException &e) {
    char *r = new char[90];
    sprintf_s(r, 90, "Sum with argument (n=%lf) with call another function", n);
    throw ContainException(r, new MyException(e));
  }
}

double Test4(long double n) {
  try {
    return Sum(n);
  }
  catch (MyException& e) {
    char *r = new char[90];
    sprintf_s(r, 90,
              "Test4 with argument (n=%lf) with call another function", n);
    throw ContainException(r, new MyException(e));
  }
}
