// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include "02.count_set_bit.c"

static void test_count_set_bit(void **state) {
  struct Test {
    int n;
    int expected;
  };

  struct Test tests[] = {{0, 0}, {1, 1}, {2, 1},  {3, 2},   {4, 1},   {5, 2},
                         {6, 2}, {7, 3}, {37, 3}, {255, 8}, {1024, 1}};

  int n = sizeof(tests) / sizeof(struct Test);

  for (int i = 0; i < n; i++) {
    struct Test test = tests[i];
    int numBitV1 = countSetBitV1(test.n);
    assert_int_equal(numBitV1, test.expected);

    int numBitV2 = countSetBitV2(test.n);
    assert_int_equal(numBitV2, test.expected);

    int numBitV3 = countSetBitV3(test.n);
    assert_int_equal(numBitV3, test.expected);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_count_set_bit),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
