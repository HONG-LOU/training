/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 21:26:44
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n);
  std::vector<bool> c(n, false);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }  
  std::function<void(int)> dfs = [&] (int x) {
    c[x] = true;
    ++ans;
    if (ans >= 1000000) {
      std::cout << ans << "\n";
      exit(0);
    }
    for (auto p : a[x]) if (!c[p]) {
      dfs(p);
    }
    c[x] = false;
  };
  dfs(0);
  std::cout << ans << "\n";
  return 0;
}