#include <search.h>
#include <windows.h>

int CmpDouble(const void *arg1, const void *arg2) {
  const double arg1_as_double = *static_cast<const double *>(arg1),
               arg2_as_double = *static_cast<const double *>(arg2);

  if (arg1_as_double - arg2_as_double < 0) {
    return -1;
  } else if (arg1_as_double-arg2_as_double > 0) {
    return 1;
  } else {
    return 0;
  }
}

double Sort(double *mas, int size) {
  LARGE_INTEGER freq;
  LARGE_INTEGER start, finish;
  QueryPerformanceFrequency(&freq);

  QueryPerformanceCounter(&start);
  qsort(mas, size, sizeof(double), CmpDouble);
  QueryPerformanceCounter(&finish);

  return (finish.QuadPart - start.QuadPart)/(double)freq.QuadPart;
}
