#include <stdio.h>

int a[101010];
int dis[101010];

int f, n, m;

int ce (double e) {
  int x = (int) e;
  if (e > x) {
    return x + 1;
  }
  else {
    return x;
  }
}

int check (int d, int k) {
  int need = 0;
  int i;
  for (i = 0; i < n; i++) {
    need += dis[i] / d;
  }
  return need <= k ? 1 : 0;
}

int main () {
  scanf("%d %d %d", &f, &n, &m);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i < n; i++) {
    dis[i - 1] = a[i] - a[i - 1];
  }
  int l = 0, r = (int) 1e8, d, ans;
  while (r - l > 1) {
    d = (l + r) >> 1;
    if (check(d, m) == 1) {
      r = d;
      ans = d;
    }
    else {
      l = d;
    }
  }
  printf("%d", l);
  return 0;
}