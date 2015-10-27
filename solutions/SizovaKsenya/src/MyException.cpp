#include "MyException.h"

void MyException::WriteLog() {
  if (e != 0)
    (*e).WriteLog();
  cout << str;
  cout << endl;
}

MyException::MyException(char *str0, MyException *e0) {
  str = str0;
  e = e0;
}

MyException::MyException(const MyException &E) {
  if (E.str != 0) {
    str = new char[strlen(E.str)];
    strcpy_s( str, 300, E.str);
  }
  if (E.e != 0)
	e = new MyException ( *(E.e));
  else
    e = 0;
}

MyException::~MyException() {
  if (e != 0)
    delete e;
  delete[] str;
}
