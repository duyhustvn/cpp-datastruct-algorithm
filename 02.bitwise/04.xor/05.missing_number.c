#include <stdio.h>

/*
** Given an array nums containing n distinct numbers in the range [0, n]
** return the only number in the range that is missing from the array.
** algorithm: xor 4 consecutive numbers which starts with a even number = 0
** 0 ^ 1 ^ 2 ^ 3 = 0
** Time complexity: O(n)
** Space complexity: O(1)
*/
int findMissingNumber(int arr[], int len) {
  int carrier = (len + 1) % 4;
  if (carrier == 0) {
    carrier = 4;
  }

  int result = 0;
  for (int i = 0; i <= len - 1; i++) {
    result ^= arr[i];
  }

  for (int i = len + 1; i <= len + (4 - carrier); i++) {
    result ^= i;
  }

  return result;
}

/*
** Time complexity: O(n)
** Space complexity: O(1)
*/
int findMissingNumberV2(int arr[], int len) {
  int result = 0;
  for (int i = 0; i < len; i++) {
    result = result ^ arr[i];
  }

  for (int i = 0; i <= len; i++) {
    result = result ^ i;
  }
  return result;
}
