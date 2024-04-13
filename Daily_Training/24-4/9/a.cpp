/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 14:43:39
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, s, e;
  std::cin >> n >> m >> s >> e;
  std::vector<long long> dis(n, (1ll << 31) - 1);
  dis[s] = 0;
  std::vector<std::vector<std::array<int, 2>>> g(n);
  std::vector<int> we(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> we[i];
  }
  std::vector<int> num(n, 0);
  num[s] = 1;
  std::vector<int> c(n, 0);
  c[s] = we[s];
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  std::vector<int> nt(n, 0);
  nt[0] = s;
  int cnt = 1;
  std::vector<int> vis(n, 0);
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
      vis[x] = 1;
      for (auto [y, w] : g[x]) {
        if (vis[y]) {
          continue;
        }
        if (d + w < dis[y]) {
          dis[y] = d + w;
          num[y] = num[x];
          if (c[x] + we[y] > c[y] ) {
            c[y] = c[x] + we[y];
            nt[cnt++] = y;
            std::cout << '|' << y << ' ';
          }
          
          h.emplace(dis[y], y);
        }
        else if (d + w == dis[y]) {
          num[y] += num[x];
          if (c[x] + we[y] > c[y]) {
            c[y] = c[x] + we[y];
            // h.emplace(dis[y], y);
            nt[cnt++] = y;
            std::cout << y << ' ';
          }
        }
      }
    }
  };
  dijkstra();
  std::cout << num[e] << ' ' << c[e] << "\n";
  // for (int i = 0; i < n; i++) {
  //   std::cout << num[i] << " \n"[i == n - 1];
  // }
  // for (int i = 0; i < n; i++) {
  //   std::cout << c[i] << " \n"[i == n - 1];
  // }
  for (int i = 0; i < n; i++) {
    std::cout << nt[i] << ' ';
    if (nt[i] == e) {
      break;
    }
  }
  std::cout << "\n";
  return 0;
}