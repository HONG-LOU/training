/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 14:46:18
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    int sz = (n * (n - 1)) / 2;
    std::vector<std::vector<int>> g(sz);
    for (int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    std::vector<int> x;
    std::set<int> y;
    int yy = 0;
    std::map<int, int> cou;
    for (int i = 0; i < sz; i++) {
      if ((int) g[i].size() == 1) {
        x.push_back(i);
        y.insert(g[i][0]);
        cou[g[i][0]]++;
      }
    }
    for (auto cnt : cou) {
      yy = cnt.second;
    }
    std::cout << (int) y.size() << ' ' << yy << "\n";
  }
  return 0;
}