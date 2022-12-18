#include <stdio.h>
#include <math.h>

#define int long long

int n, m, k;

int a[20][20];
int b[20][20] = {0};

int ans = 0;

int cal (int x) {
  int sum = 0;
  while (x > 0) {
    x /= 10;
    sum++;
  }
  return sum;
}

int d[4] = {-1, 0, 1};

void dfs (int deep, int sum, int x, int y, int xp, int yp) {
  if (sum % 7 == 0 && sum != 0) {
    ans++;
  }
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j || d[i] + d[j] == 0) {
        continue;
      }
      if ((x + d[i] <= n && y + d[j] <= m && x + d[i] >= 1 && y + d[j] >= 1) && b[x + d[i]][y + d[j]] == 0) {
        b[x + d[i]][y + d[j]] = 1;
        if (a[x][y] < 10) {
          sum = sum * 10 + a[x][y];
        }
        else {
          sum = sum * 100 + a[x][y];
        }
        if (xp == d[i] && yp == d[j]) {
          dfs(deep, sum, x + d[i], y + d[j], d[i], d[j]);
        }
        else if (deep < k) {
          dfs(deep + 1, sum, x + d[i], y + d[j], d[i], d[j]);
        }
        b[x + d[i]][y + d[j]] = 0;
        if (a[x][y] < 10) {
          sum /= 10;
        }
        else {
          sum /= 100;
        }
      }
    }
  }
}

signed main () {
  scanf("%d %d %d", &n, &m, &k);
  b[1][1] = 1;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  b[1][1] = 1;
  dfs(0, 0, 1, 1, 1, 0);
  printf("%d", ans);
  return 0;
}