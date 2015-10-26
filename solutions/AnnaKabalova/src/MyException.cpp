#include "MyException.h"
MyException::MyException(char *_str, MyException*ex)
{
	str = _str;
	exc = ex;
}
MyException::MyException(MyException&ex)
{
	str = new char[strlen(ex.str)];
	strcpy_s(str, 300, ex.str);
	if (ex.exc != 0)
		exc = new MyException(*(ex.exc));
	else exc = 0;
}
MyException::~MyException()
{
	if (exc != 0)
		delete exc;
	delete[]str;
}
void MyException::WriteLog()
{
	if (exc != 0)
		exc->WriteLog();
	printf("%s\n", str);
}
