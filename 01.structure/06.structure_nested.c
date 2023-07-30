#include <stdio.h>

int main() {
  // structure address
  struct address {
    char city[20];
    long int pin;
  };

  // structure emp
  struct emp {
    char name[20];
    int age;
    struct address a;
    float salary;
  };

  struct emp e1 = {"A", 20, "Ha Noi", 44000, 40.00};
  printf("%s %d %s %ld %f\n", e1.name, e1.age, e1.a.city, e1.a.pin, e1.salary);
  return 0;
}
