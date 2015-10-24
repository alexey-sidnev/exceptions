#include "MyException.h"
#include <stdio.h>
#include <string>
MyException::MyException(int err, char* sys,MyException* e) {
  system=sys;
  errType=err;
  ex=e;
}

MyException::MyException(MyException &e) {
  if(e.system!=0){
	system = new char[strlen(e.system)];
	strcpy_s(system,90,e.system);
  }
  errType=e.errType;
  if(e.ex!=0)
	ex=new MyException(*(e.ex)); 
  else 
	ex=0;
}

MyException::~MyException() {
  if(ex!=0)
	delete ex;
  delete[] system;
}

void MyException::WriteLog() {
  if(ex!=0) 
	ex->WriteLog();
  printf("The error %s is generated in function %s.\n",errorsT[errType],system);
}
