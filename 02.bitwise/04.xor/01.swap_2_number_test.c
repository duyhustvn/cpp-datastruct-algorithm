// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "01.swap_2_number.c"

static void test_swap_2_number(void **state) {
  struct Test {
    int a;
    int b;
    int expectedA;
    int expectedB;
  };

  struct Test tests[] = {{1, 2, 2, 1}, {3, 4, 4, 3}, {-5, -6, -6, -5}};

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    swap2Number(&test.a, &test.b);
    assert_int_equal(test.a, test.expectedA);
    assert_int_equal(test.b, test.expectedB);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_swap_2_number),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
