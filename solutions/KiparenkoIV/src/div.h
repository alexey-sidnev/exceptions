#pragma once
#ifndef DIV_H
#define DIV_H

#include "MyException.h"

template <class T>
T MyDiv(T a, T b) {
	if(b==0) 
	{
		char *r=new char[50];
		sprintf(r,"MyDiv with arguments (a=%f) and (b=%f)",a,b);
		throw DivByZeroException(r);
	}
  return a / b;
}

#endif  // DIV_H
