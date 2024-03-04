/**
 *    author:  HONG-LOU
 *    created: 2024-03-03 16:41:21
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> f(n);
  std::iota(f.begin(), f.end(), 0);
  std::vector<std::array<int, 3>> e(m);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> e[i][0] >> e[i][1] >> e[i][2];
    e[i][0] -= 1;
    e[i][1] -= 1;
  }
  std::sort(e.begin(), e.end(), [&] (auto a, auto b) {
    return a[2] < b[2];
  });
  std::function<int(int)> find = [&] (int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
  };
  int total = 0;
  std::function<void()> Kruskal = [&] () {
    for (int i = 0; i < m; i++) {
      int u = find(e[i][0]);
      int v = find(e[i][1]);
      if (u == v) {
        continue;
      }
      f[u] = v;
      ans += e[i][2];
      total += 1;
      if (total == n - 1) {
        break;
      }
    }
  };
  Kruskal();
  if (total == n - 1) {
    std::cout << ans << "\n";
  }
  else {
    std::cout << "orz\n";
  }
  return 0;
}