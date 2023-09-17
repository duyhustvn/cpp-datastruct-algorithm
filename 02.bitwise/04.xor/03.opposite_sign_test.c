// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "03.opposite_sign.c"

static void test_is_opposite_sign(void **state) {
  struct Test {
    int a;
    int b;
    int expected;
  };

  struct Test tests[] = {
      {1, 1, 0},
      {1, -1, 1},
      {0, -1, 1},
      {0, 1, 0},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int output = isOppositeSign(test.a, test.b);
    assert_int_equal(test.expected, output);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_is_opposite_sign),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
