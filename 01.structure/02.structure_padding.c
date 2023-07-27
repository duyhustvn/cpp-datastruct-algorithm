#include <stdio.h>

int main() {
  // declare structure employee
  struct employee {
    char name;
    int age;
    float salary;
  };

  struct employee e1 = {'A', 20, 30.0};
  // address of struct members
  printf("%u %u %u\n", &e1.name, &e1.age, &e1.salary); // -> 16 20 24

  // Begin every new element at an address that is multiple of 1
#pragma pack(1)
  struct employeeWithPragmaPack1 {
    char name;
    int age;
    float salary;
  };

  struct employeeWithPragmaPack1 e2 = {'A', 20, 30.0};
  // address of struct members
  printf("%u %u %u\n", &e2.name, &e2.age, &e2.salary); // -> 16 17 21

// Begin every new element at an address that is multiple of 2
#pragma pack(2)
  struct employeeWithPragmaPack2 {
    char name;
    int age;
    float salary;
  };

  struct employeeWithPragmaPack2 e3 = {'A', 20, 30.0};
  // address of struct members
  printf("%u %u %u\n", &e3.name, &e3.age, &e3.salary); // -> 16 18 22

  return 1;
}
