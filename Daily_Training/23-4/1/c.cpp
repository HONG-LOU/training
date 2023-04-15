#include <bits/stdc++.h>

auto main () -> int {
  int n, m, s;
  std::cin >> n >> m;
  s = 1;
  std::vector<long long> dis(n, (1ll << 31));
  dis[s - 1] = 0;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  std::function<void()> dijkstra = [&] () {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> h;
    for (int i = 0; i < n; i++) {
      h.emplace(dis[i], i);
    }
    while (!h.empty()) {
      auto [d, x] = h.top();
      h.pop();
      if (d > dis[x]) {
        continue;
      }
      for (auto y: g[x]) {
        if (d < dis[y]) {
          dis[y] = d;
          h.emplace(dis[y], y);
        }
      }
    }
  };
  dijkstra();
  for (int i = 0; i < n; i++) {
    std::cout << dis[i] << " \n"[i == n - 1];
  }
}