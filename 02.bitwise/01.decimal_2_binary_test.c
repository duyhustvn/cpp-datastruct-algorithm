// The include section need to be in this order
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

#include <string.h>

#include "01.decimal_2_binary.c"

static void test_decimal_2_binary(void **state) {
  struct Tests {
    int n;
    char *expectedBinary;
  };

  struct Tests tests[] = {
      {0, "0"}, {1, "1"}, {10, "1010"}, {245, "11110101"}, {255, "11111111"},
  };

  int n = sizeof(tests) / sizeof(struct Tests);

  for (int i = 0; i < n; i++) {
    struct Tests test = tests[i];
    char *res = decimal2Binary(test.n);
    assert_string_equal(res, test.expectedBinary);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_decimal_2_binary),
  };

  cmocka_set_message_output(CM_OUTPUT_SUBUNIT);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
