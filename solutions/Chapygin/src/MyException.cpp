#include "MyException.h"
#include <stdio.h>

MyException::MyException(char* _eM, char* _eP, MyException* _prevEx) {
  sprintf_s(errorMessage, MAX_LEN, _eM);
  sprintf_s(errorPosition, MAX_LEN, _eP);
  prevEx = _prevEx;
}

MyException::MyException(const MyException& excp) {
  sprintf_s(errorMessage, MAX_LEN, excp.errorMessage);
  sprintf_s(errorPosition, MAX_LEN, excp.errorPosition);
  if (prevEx != NULL) prevEx = new MyException(*(excp.prevEx));
}

MyException::~MyException() {
  if (prevEx != NULL) {
    delete prevEx; prevEx = NULL;
  }
}

void MyException::WriteLog() {
  if (prevEx != NULL) prevEx->WriteLog();
  printf("--Error Type: %s; \n--Error Position: %s;\n",
  errorMessage, errorPosition);
}
