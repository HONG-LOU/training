/**
 *    author:  HONG-LOU
 *    created: 2023-05-06 20:28:34
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    bool ok = false;
    std::vector<bool> vis(n, false);
    std::function<void(int, int)> dfs = [&] (int cnt, int deep) {
      for (int i = 0; i < n; i++) {
        if (deep == 0) {
          cnt = a[i];
          dfs(cnt, deep + 1);
        }
        if (!vis[i] && std::__gcd(cnt, a[i]) < deep + 2) {
          vis[i] = true;
          if (deep == n) {
            ok = true;
            return;
          }
          dfs(std::__gcd(cnt, a[i]), deep + 1);
          vis[i] = false;
        }
      }
    };
    dfs(0, 0);
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}