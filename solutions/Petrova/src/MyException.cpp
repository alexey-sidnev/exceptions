#include "MyException.h"

MyException :: MyException (char *str1, MyException *ex1)
{
	str = str1;
	ex = ex1;
}

MyException :: MyException (const MyException &EX)
{
	str = EX.str;
	ex = EX.ex;
}

void MyException::WriteLog() {

	cout << str <<endl;
}