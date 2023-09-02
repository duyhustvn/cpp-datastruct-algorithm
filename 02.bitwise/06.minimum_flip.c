//  We have three positives numbers, a, b, and c. We have to find the minimum
//  flips required in some bits of a, b to make (a OR (b == c))

#include <stdio.h>

int minimumFlip(int a, int b, int c) {
  int count = 0;
  for (int i = 0; i < 32; i++) {
    int bitC = (c >> i) & 1;
    int bitA = (a >> i) & 1;
    int bitB = (b >> i) & 1;

    if ((bitA | bitB) == bitC) {
      continue;
    }

    if (bitC == 1) {
      count++;
    } else if (bitC == 0) {
      if (bitA == 1 && bitB == 1) {
        count += 2;
      } else {
        count++;
      }
    }
  }

  return count;
}
