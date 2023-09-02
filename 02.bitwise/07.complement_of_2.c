#include <stdio.h>

// 2's complement:  Negative numbers in two's complement are represented by
// taking the bitwise NOT (complement) of the corresponding positive number (1's
// complement) and then adding 1 to the result (2's complement)
//
//  8          = 0000.0000.0000.0000.0000.0000.0000.1000
// -8 = ~8 + 1 = 1111.1111.1111.1111.1111.1111.1111.0111
//             + 0000.0000.0000.0000.0000.0000.0000.0001
//             = 1111.1111.1111.1111.1111.1111.1111.1000
//
//  5          = 0000.0000.0000.0000.0000.0000.0000.0101
// -5 = ~5 +1  = 1111.1111.1111.1111.1111.1111.1111.1010
//             + 0000.0000.0000.0000.0000.0000.0000.0001
//             = 1111.1111.1111.1111.1111.1111.1111.1011

void printBinary(int n) {
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
    if (i % 4 == 0 && i != 0) {
      printf(".");
    }
  }
  printf("\n");
}

int negative(int n) { return ~n + 1; }

int positive(int n) { return ~(n - 1); };

int main() {
  int pn; // positive number
  int nn; // negative number
  pn = 8;
  printf("%10d: ", pn);
  printBinary(pn);

  nn = negative(pn);
  printf("%10d: ", nn);
  printBinary(nn);

  pn = positive(nn);
  printf("%10d: ", pn);
  printBinary(pn);

  printf("\n");

  pn = 5;
  printf("%10d: ", pn);
  printBinary(pn);

  nn = negative(pn);
  printf("%10d: ", nn);
  printBinary(nn);

  pn = positive(nn);
  printf("%10d: ", pn);
  printBinary(pn);
}
