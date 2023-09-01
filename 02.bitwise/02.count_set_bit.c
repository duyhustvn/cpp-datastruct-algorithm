#include <stdio.h>

#include <math.h>

// Time complexity: O(log2(n))
// Space complexity: O(1)
int countSetBitV1(int n) {
  int count = 0;

  while (n != 0) {
    count += (n & 1);
    n = n >> 1;
  }

  return count;
}

// Time complexity: O(number of 1 bit)
// Space complexity: O(1)
int countSetBitV2(int n) {
  int count = 0;

  while (n != 0) {
    n &= n - 1;
    count++;
  }

  return count;
}
