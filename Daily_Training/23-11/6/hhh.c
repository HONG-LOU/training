#include <stdio.h>

int minesoneday(int day, int x) {
  printf("%d %d\n", day, x);
  if (day == 5) {
    return x;
  }
  int ans = x / 2;
  ans -= 1;
  return minesoneday(day + 1, ans);
}

int main () {
  int ans = minesoneday(1, 46);
  printf("%d", ans);
  return 0;
}