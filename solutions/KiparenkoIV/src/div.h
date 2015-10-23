#pragma once
#ifndef DIV_H
#define DIV_H

#include "MyException.h"

template <class T>
T MyDiv(T a, T b) {
	if(b==0) 
	{
		char *r=new char[90];
		sprintf_s(r,90,"MyDiv with arguments (a=%lf) and (b=%lf)",a,b);
		throw DivByZeroException(r);
	}
  return a / b;
}

#endif  // DIV_H
