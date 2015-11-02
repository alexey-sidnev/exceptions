#include "MyException.h"

void MyException::WriteLog() {
  if (prevEx != 0)  prevEx -> WriteLog();
  printf("%s\n", errLog);
}

MyException::MyException(char* _errLog, MyException* _prevEx) {
  errLog = _errLog;
  prevEx = _prevEx;
}

MyException::MyException(const MyException& excp) {
  if (excp.errLog != NULL) {
    errLog = new char[strlen(excp.errLog)];
    strcpy_s(errLog, MAX_LEN, excp.errLog);
  }
  if (excp.prevEx != NULL) {
    prevEx = new MyException ( *(excp.prevEx));
  } else {
    prevEx = NULL;
  }
}

MyException::~MyException() {
  if (prevEx != NULL)  delete prevEx;
  delete[] errLog;
}
