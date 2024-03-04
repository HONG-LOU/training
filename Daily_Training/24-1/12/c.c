#include <stdio.h>

int main () {

  int n, m;
  scanf("%d %d", &n, &m);

  int ans = 0;

  int i;

  for (i = n; i <= m; i++) {
    int sum = 0;
    int cnt = i;

    while (cnt) {
      sum += cnt % 10;
      cnt /= 10;
    }
    
    if (sum % 4 == 0) {
      ans++;
    }
  }

  printf("%d", ans);
  return 0;
}