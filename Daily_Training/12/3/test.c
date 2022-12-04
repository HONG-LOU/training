#include <stdio.h>
#include <string.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  char a[101010];
  scanf("%s", &a);
  int dp[101010];
  int i, j;
  for (i = 0; i < 101010; i++) {
    dp[i] = 1;
  }
  int n = strlen(a);
  for (i = 1; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (a[i] >= a[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }
  int ans = 0;
  for (i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}