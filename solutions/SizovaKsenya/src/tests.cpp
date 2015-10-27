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
#define l 100

void Test1(unsigned int size) {
	double minTime = std::numeric_limits<double>::max(),
		maxTime = 0.,
		avgTime = 0.;
	double *mas = 0;
	try {
		mas = new double[size];
	}
	catch(...) {
		char *s = new char[l];
		sprintf_s(s, l, "Exception MemoryNotAllocated: Too much memory for allocation in operator new (size=%u)", size);
		throw Exception1(s, 0);
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
		catch (MyException &e) {
			char *s = new char[l];
			sprintf_s(s, l, "Exception DivisionByZero: MyDiv with arguments (x=%lf) and (y=%lf)", x, y);
			throw Exception2(s, new MyException(e));
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
		char *s = new char[l];
		sprintf_s(s, l, "Exception BadTypeCast: Error in dynamic_cast.");
		throw Exception3(s, 0);
	}
	printf("Test3 passed.\n");
}


double Sum(long double n) {
	if (n < 0) return 0.;
	if (n == 0.||n==-0.)   
	{
		char *s = new char[l];  
		sprintf_s(s,l,"Exception DivisionByZero: Argument is zero in function Sum");  
		throw Exception3(s,0);  
	}  
	try {  
		return 1./n + Sum(n - 1);  
	}   
	catch (MyException &e) {
		char *s = new char[l];
		sprintf_s(s, l, "Exception WrongArgument:(n=%lf)", n);
		throw Exception4(s, new MyException(e));
	}
}

double Test4(long double n) {
	try {
		return Sum(n);
	}  
	catch (MyException &e) {
		char *s = new char[l];
		sprintf_s(s, l, "Exception WrongArgument: (n=%lf)", n);
		throw Exception4(s, new MyException(e));
	}
}
