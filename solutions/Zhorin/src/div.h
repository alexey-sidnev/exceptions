#pragma once
#ifndef DIV_H
#define DIV_H
#include "locale.h"
#include "MyException.h"

template <class T>
T MyDiv(T a, T b) {
	setlocale(LC_ALL, "Russian");
	if (b == 0){
		char*Log1 = new char[300];
		sprintf(Log1, "Произошло деление на ноль, входные параметры:(a=%lf) и (b=%lf)", a, b);

		throw DivByZero(Log1, 0);
	}
	return a / b;

}

#endif  // DIV_H
