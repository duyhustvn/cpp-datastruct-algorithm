// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "05.missing_number.c"

static void test_find_missing_number(void **state) {
  struct Test {
    int arr[7];
    int expectedMissing;
  };

  struct Test tests[] = {
      {{0, 1, 2, 3, 4, 5, 6}, 7}, {{0, 1, 2, 3, 4, 5, 7}, 6},
      {{0, 1, 2, 3, 4, 6, 7}, 5}, {{0, 1, 2, 3, 5, 6, 7}, 4},
      {{0, 1, 2, 4, 5, 6, 7}, 3}, {{0, 1, 3, 4, 5, 6, 7}, 2},
      {{0, 2, 3, 4, 5, 6, 7}, 1}, {{1, 2, 3, 4, 5, 6, 7}, 0},
  };

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int output;
    output = findMissingNumberV2(test.arr, 7);
    assert_int_equal(test.expectedMissing, output);

    output = findMissingNumberV2(test.arr, 7);
    assert_int_equal(test.expectedMissing, output);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_find_missing_number),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
