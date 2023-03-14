/**
 *    author:  HONG-LOU
 *    created: 2023-03-07 20:42:11
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
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    std::vector<bool> used(n, false);
    used[i] = true;
    std::queue<int> Q;
    Q.push(i);
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      for (int w : g[v]) {
        if (!used[w]) {
          used[w] = true;
          Q.push(w);
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (j != i && used[j]) {
        cnt++;
      }
    }
  }
  std::cout << cnt - m << "\n";
  return 0;
}