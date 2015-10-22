#pragma once
#ifndef DIV_H
#define DIV_H
#include "string.h"

template <class T>
T MyDiv(T a, T b) {
	if (b == 0)
	{
		char *st = new char [100];
		sprintf(st,"MyDiv parem: a=%lf b = %lf", a, b);
		throw test2(st, 0);
	}
	//if (b!=0)
		return a / b;
}
#endif  // DIV_H
