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

char *decimal2Binary(int n) {
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
