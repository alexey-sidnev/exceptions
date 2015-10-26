#define _CRT_SECURE_NO_WARNINGS
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
#define MAX_LEN 100

void Test1(unsigned int size) {
  double minTime = std::numeric_limits<double>::max(),
    maxTime = 0.,
    avgTime = 0.;
  double *mas = 0;
  try {
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
	  printf("Test1 (%i) passed:\n\tmin = %lf, max = %lf, avg = %lf\n", size,
		  minTime, maxTime, avgTime);
	  delete[] mas;
  }
  catch (...) {
	  throw(AllocationExcp("Error in Test 1", 0));
  }
}

void Test2() {
  for (int i = 0; i < EXP_TEST2_COUNT; i++) {
    long double x = rand();
    long double y = rand();
	try{
		MyDiv(x, y);
	}
	catch (MyException& ex) {
		throw DivisionByZeroExcp("Error in Test 2", new MyException(ex));
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
	catch (...){
		char temp[MAX_LEN];
		char btype;
		if (b->member()) btype = 'B';
		else btype = 'A';
		sprintf(temp, "Object b is '%c' type", e);
		throw CastExcp(temp, 0);
	}
  printf("Test3 passed.\n");
}

double Sum(long double n) {
  if (n < 0) return 0.;
  if (n == 0. || n == -0.) throw DivisionByZeroExcp("Error in sum function", NULL);
  try { 
    return 1./n + Sum(n - 1);
  } 
  catch (MyException &excp) {
	  throw SumExcp("Error in sum function", new MyException(excp));
  }
}

double Test4(long double n) {
  try {
  return Sum(n);
  }
  catch (MyException& excp) {
	  char arg[MAX_LEN];
	  sprintf(arg, "Error in test 4, arg = %lf", n);
	  throw SumExcp(arg, new MyException(excp));
  }
}
