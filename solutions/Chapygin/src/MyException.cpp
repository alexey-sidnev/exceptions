#include "MyException.h"
#include <stdio.h>
#include <string>

MyException::MyException(char* _errorMessage, char* _errorPosition, MyException* _prevEx) {
	strcpy(errorMessage, _errorMessage);
	strcpy(errorPosition, _errorPosition);
	prevEx = _prevEx;
}

MyException::MyException(const MyException& excp) {
	strcpy(errorMessage, excp.errorMessage);
	strcpy(errorPosition, excp.errorPosition);
	if (prevEx != NULL) prevEx = new MyException(*(excp.prevEx));
}

MyException::~MyException(){
	if (prevEx != NULL) {
		delete prevEx; prevEx = NULL;
	}
}

void MyException::WriteLog() {
	if (prevEx != NULL) prevEx->WriteLog();
	printf("--Error Type: %s; \n--Error Position: %s;\n", errorMessage, errorPosition);
}
