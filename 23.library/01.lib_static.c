int factorial(int num) {
  int i;
  int p = 1;
  for (i = 1; i <= num; i++) {
    p = p * i;
  }
  return p;
}
