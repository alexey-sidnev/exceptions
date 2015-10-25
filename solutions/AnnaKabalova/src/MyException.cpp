#include "MyException.h"

void MyException::WriteLog()
{
	if (exc != 0)
		exc->WriteLog();
	printf("%s\n", str);
}
