#include <stdio.h>

int main() {
  struct book {
    char n[20];
    int nop;
    float pr;
  };
  struct book b = {"Basic", 425, 135.00};
  struct book *ptr = &b;
  printf("%s %d %f\n", b.n, b.nop, b.pr);
  printf("%s %d %f\n", ptr->n, ptr->nop, ptr->pr);

  // pointer to array of structure
  struct employee {
    char name;
    int age;
    float salary;
  };

  struct employee ems[] = {
      {'A', 23, 400.5},
      {'B', 24, 300.5},
      {'C', 25, 500.5},
  };

  // pointer to char
  char *p = (char *)ems;
  // pointer to structure
  struct employee *q = ems;
  // pointer to an array of structure
  struct employee(*r)[3] = (struct employee(*)[3])ems;

  // Common programming error: z = e is wrong because an array name can never
  // occur on the left-hand side of =.
  // You cannot reassign the array name to point to a different memory location
  // This assignment is not allowed in C because it attempts to change the
  // memory address that z points to. In C, you cannot reassign the array name
  // to point to a different memory location. struct employee *z[3] = ems;

  printf("%u\n", p);
  printf("%u\n", q);
  printf("%u\n", r);
  p++;
  q++;
  r++;
  printf("%u\n", p);
  printf("%u\n", q);
  printf("%u\n", r);

  return 0;
}
