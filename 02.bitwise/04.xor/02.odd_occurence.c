#include <stdio.h>

/* Every element appears an even number of times except for
 * one element, which appears an odd number of times. Find it
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int getOddOccurence(int arr[], int length) {
  int a = arr[0];
  for (int i = 1; i < length; i++) {
    a = a ^ arr[i];
  }

  return a;
}
