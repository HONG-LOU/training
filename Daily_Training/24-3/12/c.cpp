/**
 *    author:  HONG-LOU
 *    created: 2024-03-12 20:34:16
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> used(n, 0);
  std::vector<int> cnt(k);
  std::function<void(int)> dfs = [&] (int deep) {
    if (deep == k) {
      for (int i = 0; i < k; i++) {
        std::cout << cnt[i] << " \n"[i == k - 1];
      }
      return;
    }
    for (int i = 0; i < n; i++) {
      if (used[i] == 0) {
        cnt[deep] = i + 1;
        used[i] = 1;
        dfs(deep + 1);
        used[i] = 0;
      }
    }
  };
  dfs(0);
  return 0;
}