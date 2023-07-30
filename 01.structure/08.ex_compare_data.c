#include <stdio.h>

struct date {
  int day, month, year;
};

int isValidDate(struct date d);
int compareDates(struct date d1, struct date d2);

int main() { return 0; }

int isValidDate(struct date d) {
  if (d.day < 0 || d.day > 31 || d.month < 0 || d.month > 12 || d.year < 1000 ||
      d.year > 9999) {
    return -1;
  }
  return 0;
}

int compareDates(struct date d1, struct date d2) {
  if (isValidDate(d1) == -1 || isValidDate(d2) == -1) {
    return -1;
  }

  if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) {
    return 0;
  }

  return 1;
}
