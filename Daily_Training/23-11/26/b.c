#include <stdio.h>

int cnt[25] = {0};
int used[25] = {0};

int n;

void print() {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", cnt[i]);
  }
  printf("\n");
}

int check(int x) {
  int i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

void dfs(int deep) {
  if (deep == n - 1) {
    if (check(cnt[0] + cnt[n - 1])) print();
    return;
  }
  int i;
  for (i = 1; i <= n; i++) {
    if (!used[i] && check(cnt[deep] + i)) {
      cnt[deep + 1] = i;
      used[i] = 1;
      dfs(deep + 1);
      used[i] = 0;
    }
  }
}

int main () {
  scanf("%d", &n);
  cnt[0] = 1;
  used[1] = 1;
  dfs(0);
  return 0;
}