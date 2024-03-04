#include <stdio.h>

int a[10101] = {0};

int main () {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (i = 0; i < n; i++) {
    if (a[i] != i + 1) {
      int t = a[i];
      int j;
      for (j = i + 1; j < n; j++) {
        if (a[j] == i + 1) {
          a[j] = t;
          a[i] = i + 1;
          ans++;
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}