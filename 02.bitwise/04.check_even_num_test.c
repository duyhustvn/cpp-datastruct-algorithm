// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "04.check_even_num.c"

static void test_is_even_num(void **state) {
  struct Test {
    int n;
    int expected;
  };

  struct Test tests[] = {{0, 1}, {1, 0}, {2, 1}, {3, 0}};

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    int res = isEvenNumber(i);
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
