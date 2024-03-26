/**
 *    author:  HONG-LOU
 *    created: 2024-03-12 19:48:57
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    std::sort(g[i].begin(), g[i].end());
  }
  std::vector<int> vis(n, 0);

  //dfs
  std::function<void(int)> dfs = [&] (int cnt) {
    vis[cnt] = 1;
    std::cout << cnt + 1 << ' ';
    for (auto next : g[cnt]) {
      if (!vis[next]) {
        dfs(next);
      }
    }
  };
  dfs(0);
  std::cout << "\n";

  // bfs
  std::queue<int> q;
  q.push(0);
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }
  while (!q.empty()) {
    auto cnt = q.front();
    q.pop();
    vis[cnt] = 1;
    std::cout << cnt + 1 << ' ';
    for (auto next : g[cnt]) {
      if (!vis[next]) {
        q.push(next);
        vis[next] = 1;
      }
    }
  }
  return 0;
}












/*

W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/