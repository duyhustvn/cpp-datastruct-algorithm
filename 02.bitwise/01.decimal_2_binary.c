#include <stdio.h>
#include <stdlib.h>

void revertString(char *str, int n) {
  int left = 0, right = n - 1;
  while (left < right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

// Time complexity: O(log2(n))
// Space complexity: O(log2(n))
char *decimal2BinaryUsingRSA(int n) {
  // Using Right Shift (>>) and And(&)
  char *res = (char *)malloc(32 * sizeof(char));

  if (n == 0) {
    return "0";
  }

  int i = 0;

  while (n != 0) {
    int v = n & 1;
    int written = snprintf(res + i, 2, "%d", v);

    n = n >> 1;

    i++;
  }
  revertString(res, i);

  return res;
}

// Time complexity: O(log2(n))
// space complexity: O(1)
char *decimal2BinaryUsingBitwise(int n) {
  // Using Bitwise only work with fixed binary length
  // assuming 32-bit integer
  char *res = (char *)malloc(32 * sizeof(char));

  for (int i = 31; i >= 0; i--) {
    int mask = (1 << i);

    if (n & mask) {
      res[i] = '1';
    } else {
      res[i] = '0';
    }
  }
  revertString(res, 32);

  return res;
}
