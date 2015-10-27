#include "MyException.h"

void MyException::WriteLog() {

	if (prev != 0)
		(*prev).WriteLog();
	cout << Log
		<< endl;
}
MyException::MyException(char*Log_1, MyException *prev_1){
	Log = Log_1;
	prev = prev_1;

}
MyException::MyException(const MyException&ex){
	if (ex.Log != 0)
	{
		Log = new char[strlen(ex.Log)];
		strcpy_s(Log, 300, ex.Log);
	}

	if (ex.prev != 0)
		prev = new MyException(*(ex.prev));
	else
		prev = 0;

}
MyException::~MyException(){
	{
		if (prev != 0) delete prev;
		delete[] Log;
	}

}


