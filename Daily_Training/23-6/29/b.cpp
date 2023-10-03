/**
 *    author:  HONG-LOU
 *    created: 2023-06-29 20:35:46
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, s;
  std::cin >> n >> m >> s;
  std::vector<long long> dis(n, (1ll << 31) - 1);
  dis[s - 1] = 0;
  std::vector<std::vector<std::array<int, 2>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
  }
  
  return 0;
}