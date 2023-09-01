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

// Time complexity: O(1)
// Space complexity: O(1)
int countSetBitV3(int n) {
  int table[256];

  for (int i = 0; i < 256; i++) {
    table[i] = (i & 1) + table[i >> 1];
  }

  int maxBit = log2(n);
  int group = maxBit / 8;

  int count = 0;
  for (int i = 0; i <= n; i++) {
    count += table[n & 0xff]; // 0xff = 1111.1111
    n = n >> 8;
  }
  return count;
}
