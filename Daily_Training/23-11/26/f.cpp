/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 17:15:24
**/
#include <bits/stdc++.h>

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> check(n + 1, 0);
  std::vector<int> c(n + 1, 0);
  std::vector<std::vector<int>> g(n + 1, std::vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  std::function<void(int, int)> dfs = [&] (int as, int deep) {
    for (int de : g[deep]) {
      if (de == as) {
        continue;
      }
      dfs(deep, de);
      if (!check[deep] && !check[de]) {
        check[deep] = deep;
        check[de] = deep;
      }
    }
  };
  std::function<void(int, int)> codfs = [&] (int as, int deep) {
    for (int de : g[deep]) {
      if (de == as) {
        continue;
      }
      if (check[de] == check[deep]) {
        c[de] = c[deep];
      }
      else {
        c[de] = !c[deep];
      }
      codfs(deep, de);
    }
  };
  dfs(-1, 1);
  for (int i = 1; i <= n; i++) {
    if (check[i] <= 0) {
      std::cout << -1;
      return 0;
    }
  }
  c[1] = 1;
  codfs(-1, 1);
  for (int i = 1; i <= n; i++) {
    std::cout << (c[i] == 1 ? 'R' : 'B');
  }
  return 0;
}