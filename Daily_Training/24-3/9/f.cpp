/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 18:16:25
**/
#include <bits/stdc++.h>

int cnt[20] = {0};
int used[20] = {0};
int n = 0;

void dfs(int deep) {
  if (deep == n) {
    for (int i = 1; i <= n; i++) {
      std::cout << cnt[i] << " \n"[i == n];
    }
    return;
  }
  for (int i = 1;i <= n; i++) {
    if (!used[i]) {
      used[i] = 1;
      cnt[deep + 1] = i;
      dfs(deep + 1);
      used[i] = 0;
    }
  }
}

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n;
  dfs(0);
  return 0;
}