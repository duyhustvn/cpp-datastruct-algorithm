#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)
int isPowerOf2(int n) {
  if (n == 0)
    return 0;

  int count = 0; // count number of bit 1
  return (n &= n - 1) == 0;
}
