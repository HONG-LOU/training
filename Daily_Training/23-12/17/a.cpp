/**
 *    author:  HONG-LOU
 *    created: 2023-12-17 15:02:13
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      std::cin >> u >> v;
      u--, v--;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((int) a[i].size() >= 3) {
        ans += ((int) a[i].size() - 2);
      }
    }
    std::cout << 1 + ((ans + 1) / 2) << "\n";
  }
  return 0;
}