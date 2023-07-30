#include <stdio.h>

struct book {
  char n[20];
  int nop;
  float pr;
};

void display(char *n, int nop, float pr);
void display1(struct book b);
void show(char *n, int *nop, float *pr);
void show1(struct book *b);

int main() {
  struct book b = {"C basic", 425, 135.0};
  display(b.n, b.nop, b.pr);
  show(b.n, &b.nop, &b.pr);
  display1(b);
  show1(&b);
  return 0;
}

// pass by value
void display(char *n, int nop, float pr) { printf("%s %d %f\n", n, nop, pr); }

// pass by reference
void show(char *n, int *nop, float *pr) { printf("%s %d %f\n", n, *nop, *pr); };

// pass by value
void display1(struct book b) { printf("%s %d %f\n", b.n, b.nop, b.pr); };

// pass by reference
void show1(struct book *b) { printf("%s %d %f\n", b->n, b->nop, b->pr); };
