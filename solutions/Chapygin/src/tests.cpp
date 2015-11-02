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
#define MAX_LEN 300

void Test1(unsigned int size) {
  double minTime = std::numeric_limits<double>::max(),
    maxTime = 0.,
    avgTime = 0.;
  double *mas = 0;
  try {
    mas = new double[size];
  }
  catch(...) {
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Trying to allocate size = %d", size);
    throw AllocationExcp(log, 0);
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
    double x = rand();
    double y = rand();
    try {
      MyDiv(x, y);
    }
    catch (MyException& excp) {
      char* log = new char[MAX_LEN];
      sprintf_s(log, MAX_LEN, "Trying to divide %lf/%lf", x, y);
      throw DivisionByZeroExcp(log, new MyException(excp));
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
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Bad Cast!");
    throw CastExcp(log, 0);
  }
  printf("Test3 passed.\n");
}

double Sum(long double n) {
  if (n < 0) return 0.;
  if (n == 0.|| n == -0.) {
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Trying to divide by 0");
    throw DivisionByZeroExcp(log, 0);
  }
  try {
    return 1./n + Sum(n - 1);
  }
  catch (MyException& excp) {
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Function sum called w/ argument %lf", n);
    throw SumExcp(log, new MyException(excp));
  }
}

double Test4(long double n) {
  try {
    return Sum(n);
  }
  catch (MyException &excp) {
    char* log = new char[MAX_LEN];
    sprintf_s(log, MAX_LEN, "Test 4 w/ argument %lf", n);
    throw SumExcp(log, new MyException(excp));
  }
}
