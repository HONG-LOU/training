/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:13:07
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::map<int, bool> mp;
    bool ok = false;
    std::function<void(int)> dfs = [&] (int x) {
      if (x == m) {
        ok = true;
        return;
      }
      if (x % 3 == 0 && x != 0) {
        mp[(x / 3) * 2] = true;
        mp[x / 3] = true;
        dfs(x / 3);
        dfs((x / 3) * 2);
      }
    };
    dfs(n);
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}