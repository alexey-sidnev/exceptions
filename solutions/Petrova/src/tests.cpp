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

  try
  {
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
  catch(...)
  {
	  throw test1("No mem", 0);
  }
}  

void Test2() {
  for (int i = 0; i < EXP_TEST2_COUNT; i++) {
    double x = rand();
    double y = rand();
	try{
    MyDiv(x, y);
  }
  catch(test2 &e)
  {
	  char *st = new char[100];
	  sprintf(st, "div by zero %lf %lf", x, y);
	  throw test2(st, new MyException(e));
  }

  }
  
  printf("Test2 passed.\n");  
}

void Test3(A *b) {
	char c;
	try
	{
		if (dynamic_cast<B&>(*b).member()) {
			printf("Class A\n");
		}
		else {
			printf("Class B\n");
		}
	}
	catch(...)
	{
		if (b->member())
			c = 'B';
		else
			c = 'A';
		char *str_1 = new char[100];
		sprintf(str_1, "test 3 passed with arg (b=%c)", c);

		throw test3(str_1, 0);
	}

	printf("Test3 passed.\n");
}

