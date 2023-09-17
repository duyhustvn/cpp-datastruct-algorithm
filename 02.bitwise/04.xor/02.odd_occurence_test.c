// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "02.odd_occurence.c"

static void test_get_odd_occurence(void **state) {
  struct Test {
    int arr[7];
    int expectedNum;
  };

  struct Test tests[] = {
      {{1, 1, 2, 3, 3, 3, 3}, 2},
      {{2, 1, 2, 3, 3, 4, 4}, 1},
      {{0, 0, 0, 0, 0, 0, 1}, 1},
      {{1, 1, 1, 1, 1, 0, 1}, 0},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int sz = sizeof(test.arr) / sizeof(int);
    int output = getOddOccurence(test.arr, sz);
    assert_int_equal(test.expectedNum, output);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_get_odd_occurence),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
