// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "05.is_power_of_two.c"

static void test_is_power_of_two(void **state) {
  struct Test {
    int n;
    int expected;
  };

  struct Test tests[] = {
      {0, 0}, {1, 1}, {2, 1}, {3, 0}, {4, 1},  {5, 0},
      {6, 0}, {7, 0}, {8, 1}, {9, 0}, {10, 0}, {11, 0},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    int res = isPowerOf2(tests[i].n);
    assert_int_equal(res, tests[i].expected);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_is_power_of_two),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
