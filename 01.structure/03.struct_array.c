#include <stdio.h>

int main() {
  struct employee {
    char name;
    int age;
    float salary;
  };

  struct employee e[] = {
      {'A', 23, 300.1},
      {'B', 24, 400.1},
      {'C', 25, 500.1},
  };

  int i;
  for (i = 0; i < 3; i++) {
    struct employee em = e[i];
    printf("%c %d %f\n", em.name, em.age, em.salary);
  }
}
