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
#define _CRT_SECURE_NO_WARNINGS
void Test1(unsigned int size) {
  double minTime = std::numeric_limits<double>::max(),
  maxTime = 0.,
  avgTime = 0.;
  double *mas = 0;
  try {
  mas = new double[size];
  }
  catch (...) {
  char *st = new char[300];
  sprintf_s(st, 300, "Test 1 with size=%u", size);
  throw NoMem(st, 0);
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
  catch (divZero&dex) {
  char *st = new char[300];
  sprintf_s(st, 300, "Test 2 MyDiv arg %lf %lf", x, y);
  throw divZero(st, new MyException(dex));
  }
  }
  printf("Test2 passed.\n");
}

void Test3(A *b) {
  try {
  if (dynamic_cast<B&>(*b).member()) {
  printf("Class A\n");
  }
  else {
  printf("Class B\n");
  }
  }
  catch (...) {
  char *st = new char[300];
  char c;
  if (b->member())
  c = 'B';
  else
  c = 'A';
  sprintf_s(st, 300, "Test 3 arg: %c", c);
  throw DynExc(st, 0);
  }
  printf("Test3 passed.\n");
}

double Sum(long double n) {
  if (n < 0) return 0.;
  if (n == 0. || n == -0.){
  char*st = new char[300];
  sprintf_s(st, 300, "div by zero");
  throw divZero(st, 0);
  }
  try {
  return 1. / n + Sum(n - 1);
  }
  catch (MyException &e) {
  char*st = new char[300];
  sprintf_s(st, 300, "Sum arg: (n=%lf)", n);
  throw SumExc(st, new MyException(e));
  }
}

double Test4(long double n) {
  try {
  return Sum(n);
  }
  catch (MyException &e) {
  char*st = new char[300];
  sprintf_s(st, 300, "Test4 arg: (n=%lf)", n);
  throw SumExc(st, new MyException(e));
  }
}
