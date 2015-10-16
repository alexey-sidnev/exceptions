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
  mas = new double[size];
 
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
    MyDiv(x, y);
  }

  printf("Test2 passed.\n");
}

void Test3(A *b) {
  if (dynamic_cast<B&>(*b).member()) {
    printf("Class A\n");
  } else {
    printf("Class B\n");
  }

  printf("Test3 passed.\n");
}
