#include <stdio.h>

int main () {
  int a[10];
  for (int i = 1; i <= 10; i++) {
    a[i - 1] = i;
  }
  int k, s, i;
  float ave;
  for (k = s = i = 0; i < 10; i++) {
    if (a[i] % 2 == 0) {
      continue;
    }
    s += a[i];
    k++;
  }
  if (k != 0) {
    ave = s / k;
    printf("%d,%.2f\n", k, ave);
  }
}