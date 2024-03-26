/**
 *    author:  HONG-LOU
 *    created: 2024-03-12 19:30:03
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<long long> dis(n, (1ll << 31) - 1);
  std::vector<std::vector<std::array<int, 2>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  std::function<void(int, int)> dijkstra = [&] (int s, int e) {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> h;
    std::vector<long long> dis(n, (1ll << 31) - 1);
    dis[s - 1] = 0;
    for (int i = 0; i < n; i++) {
      h.emplace(dis[i], i);
    }
    while (!h.empty()) {
      auto [d, x] = h.top();
      h.pop();
      for (auto [y, w] : g[x]) {
        if ((d ^ w) < dis[y]) {
          dis[y] = (d ^ w);
          h.emplace(dis[y], y);
        }
      }
    }
    std::cout << dis[e - 1];
  };
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    dijkstra(x, y);
  }
  return 0;
}