/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 22:07:58
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, s; // n个点，m条边，s起点
  std::cin >> n >> m >> s;
  std::vector<long long> dis(n, (1ll << 31) - 1);
  // 到每个点的最短距离，初始化为无穷大
  dis[s - 1] = 0; // 起点到起点距离0
  std::vector<std::vector<std::array<int, 2>>> g(n);
  // g[3].push_back({4, 5}) 3 -> 4有一条权值为5的边
  // n个点中每个点能走的下一个点 
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w; // 一条边 u --> v, 权值 w
    u--, v--; // 下标 0
    g[u].push_back({v, w}); // [u ---> v] = w;
  }
  std::function<void()> dijkstra = [&] () {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> h;
    // 优先队列，每次选择下一个最小的点，dis[s - 1] = 0, 自然从 起点开始
    for (int i = 0; i < n; i++) {
      h.emplace(dis[i], i);
    }
    while (!h.empty()) {
      auto [d, x] = h.top();
      // 当前点
      h.pop();
      if (d > dis[x]) {
        continue;
      }
      // 遍历与当前节点相连的所有节点进行判断
      // 当前节点+边值<下一个点值，则更新
      for (auto [y, w] : g[x]) {
        if (d + w < dis[y]) {
          dis[y] = d + w;
          h.emplace(dis[y], y);
        }
      }
    }
  };
  dijkstra();
  for (int i = 0; i < n; i++) {
    std::cout << dis[i] << " \n"[i == n - 1];
  }
  return 0;
}