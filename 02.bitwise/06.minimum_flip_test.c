// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "06.minimum_flip.c"

static void test_is_even_num(void **state) {
  struct Test {
    int a, b, c;
    int expected;
  };

  struct Test tests[] = {
      {2, 6, 5, 3},
      {2, 6, 4, 2},
      {3, 7, 4, 4},
      {10, 9, 20, 6},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int res = minimumFlip(test.a, test.b, test.c);
    assert_int_equal(res, tests[i].expected);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_is_even_num),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
