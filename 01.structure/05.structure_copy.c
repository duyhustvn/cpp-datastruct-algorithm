#include <stdio.h>
#include <string.h>

int main() {
  struct emp {
    char name[10];
    int age;
    float salary;
  };

  struct emp e1 = {"A", 21, 100.0};
  struct emp e2;

  strcpy(e2.name, e1.name);
  e2.age = e1.age;

  printf("%s %d %f\n", e1.name, e1.age, e1.salary);
  printf("%s %d %f\n", e2.name, e2.age, e2.salary);

  struct emp e3;
  e3 = e1;
  printf("%s %d %f\n", e3.name, e3.age, e3.salary);

  return 0;
}
