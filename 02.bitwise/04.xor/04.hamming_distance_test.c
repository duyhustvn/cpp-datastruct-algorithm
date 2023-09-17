// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "04.hamming_distance.c"

static void test_hamming_distance(void **state) {
  struct Test {
    int a;
    int b;
    int expectedDistance;
  };

  struct Test tests[] = {
      {1, 1, 0}, {1, 8, 2}, {12, 15, 2}, {10, 20, 4}, {0, 255, 8}, {1, 255, 7},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int output = hammingDistanceOptimal(test.a, test.b);
    assert_int_equal(test.expectedDistance, output);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_hamming_distance),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
