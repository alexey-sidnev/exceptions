#include "MyException.h"

MyException :: MyException(char *str1, MyException *ex1){
	str = str1;
	ex = ex1;
}

MyException :: MyException(const MyException &EX){
	if (EX.str != 0)
	{
		str = new char[strlen(EX.str)];
		strcpy(str, EX.str);
	}

	if (EX.ex != 0)
		ex = new MyException(*(EX.ex));
	else
		ex = 0;

}

void MyException::WriteLog(){
	if (ex != 0)
		ex->WriteLog();

	cout << str <<endl;
}

MyException :: ~MyException(){
	if (ex != 0)
		delete ex;
	delete []str;
}