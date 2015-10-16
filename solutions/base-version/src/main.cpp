#include <stdio.h>
#include <windows.h>
#include "tests.h"
#include "classes.h"
#include "MyException.h"

#define TESTS_COUNT 10

int main() {
  printf("Exceptions (start).\n");
  try {
    A a;
    B b;
    srand(666);
    
    for (int i = 0; i < TESTS_COUNT; i++) {
      int size = 0;
      unsigned char *size_as_uchar_array = (unsigned char *)&size;
      for (int j = 0; j < sizeof(int); j++)
        size_as_uchar_array[j] = rand() % 256;
      while ( size > (1 << 19) )
        size /= 2;
      try {
        Test1(size);
      }
      catch(MyException &e) {
        e.WriteLog();
      }
    }
    
    for (int i = 0; i < TESTS_COUNT; i++) {
      try {
        Test2();
      }
      catch(MyException &e) {
        e.WriteLog();
      }
    }
    
    try {
      Test3(&b);
    }
    catch(MyException &e) {
      e.WriteLog();
    }
    
    try {
      Test3(&a);
    }
    catch(MyException &e) {
      e.WriteLog();
    }
  } catch(...) { }
  
  printf("Exceptions (finish).\n");

  return 0;
}
