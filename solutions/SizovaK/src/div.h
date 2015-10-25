#pragma once
#ifndef DIV_H
#define DIV_H
#define m 100


template <class T>
T MyDiv(T a, T b) {
	if (b==0)
	{
		char *s=new char[m];
		sprintf(s,"Exception DivisionByZero: MyDiv with arguments (a=%lf) and (b=%lf)",a,b); 
		throw Exception2(s,0);
	}
	else
  return a / b;
}

#endif  // DIV_H
