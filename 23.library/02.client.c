#include <stdio.h>

#include "02.lib_dynamic.h"

int main() {
  int n1 = 5, n2 = 8;
  int f1, f2;
  f1 = factorial(n1);
  f2 = factorial(n2);
  printf("f1 = %d f2 = %d\n", f1, f2);
  return 0;
}
