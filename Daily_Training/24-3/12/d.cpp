/**
 *    author:  HONG-LOU
 *    created: 2024-03-12 20:39:57
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> cnt(n);
  std::vector<int> vis(n, 0);
  std::function<void(int)> dfs = [&] (int deep) {
    if (deep == n) {
      for (int i = 0; i < n; i++) {
        std::cout << cnt[i] << " \n"[i == n - 1];
      }
      return;
    }
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        vis[i] = 1;
        cnt[deep] = i + 1;
        dfs(deep + 1);
        vis[i] = 0;
      }
    }
  };
  dfs(0);
  return 0;
}