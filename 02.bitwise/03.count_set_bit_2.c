#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int count_set_bit(int n) {
  int count = 0;
  while (n != 0) {
    n &= n - 1;
    count++;
  }
  return count;
}

// count bit which is set to 1 for number in range from 0 to n
int *count_set_bit_range(int n) {
  int *nums = (int *)malloc((n + 1) * sizeof(int));

  for (int i = 0; i <= n; i++) {
    nums[i] = count_set_bit(i);
  }
  return nums;
}

int main() {
  int n = 6;
  int *res = count_set_bit_range(n);
  for (int i = 0; i <= n; i++) {
    printf("%d", res[i]);
  }
}
