#include <stdio.h>

/* Given integers a, b finds the positions where the corresponding bits are
 * different.
 * Time complexity: O(number of bit)
 * Space complexity: O(1)
 */
int hammingDistance(int a, int b) {
  int distance = 0;

  int tmp = a ^ b;

  while (tmp != 0) {
    if ((tmp & 1) == 1) {
      distance++;
    }
    tmp = tmp >> 1;
  }

  return distance;
}

int hammingDistanceOptimal(int a, int b) {
  int distance = 0;

  int tmp = a ^ b;

  while (tmp != 0) {
    tmp = tmp & (tmp - 1);
    distance++;
  }

  return distance;
}
