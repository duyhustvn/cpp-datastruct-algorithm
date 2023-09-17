#include <stdio.h>

/* detect if two input integers have opposite signs.
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
int isOppositeSign(int a, int b) { return (a ^ b) < 0; }
