#include <stdio.h>

int plusoneday(int day, int x) {
  printf("%d %d\n", day, x);
  if (day == 1) {
    return x;
  }
  int ans = x + 1;
  ans *= 2;
  return plusoneday(day - 1, ans);
}

int main () {
  int ans = plusoneday(5, 1);
  printf("%d", ans);
  return 0;
}