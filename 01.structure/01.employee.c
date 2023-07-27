#include <stdio.h>

int main() {
  struct employee {
    // member of structure
    char name;
    int age;
    float salary;
  };

  struct employee e1, e2;

  // assign value to structure members
  e1.name = 'A';
  e1.age = 20;
  e1.salary = 400.0;

  printf("%c %d %f\n", e1.name, e1.age, e1.salary);

  // assign values to structure members in one line
  struct employee e3 = {'B', 21, 400.1};
  printf("%c %d %f\n", e3.name, e3.age, e3.salary);

  return 0;
}
