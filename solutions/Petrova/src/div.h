#pragma once
#ifndef DIV_H
#define DIV_H
#include "string.h"

template <class T>
T MyDiv(T a, T b) {
	if (b == 0)
	{
		char *st = new char [100];
		sprintf_s(st, 100, "MyDiv perem: a=%lf b = %lf", a, b);
		throw test2(st, 0);
	}
	else
		return a / b;
}
#endif  // DIV_H
