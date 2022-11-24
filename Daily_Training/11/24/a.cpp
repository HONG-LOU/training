/**
 *    author:  HONG-LOU
 *    created: 2022-11-24 10:32:18
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> f(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  struct edge {
    int start, to;
    long long val;
  }e[202020];
  std::function<int(int)> get = [&] (int x) {
    return x == f[x] ? x : f[x] = get(f[x]);
  };
  for (int i = 1; i <= m; i++) {
    std::cin >> e[i].start >> e[i].to >> e[i].val;
  }
  std::sort(e + 1, e + m + 1, [&] (edge a, edge b) {
    return a.val < b.val;
  });
  int total = 0;
  long long ans = 0;
  std::function<void()> Kruskal = [&] () {
    for (int i = 1; i <= m; i++) {
      int u = get(e[i].start);
      int v = get(e[i].to);
      if (u == v) {
        continue;
      }
      ans += e[i].val;
      f[u] = v;
      total += 1;
      if (total == n - 1) {
        break;
      }
    }
  };
  Kruskal();
  std::cout << ans << "\n";
  return 0;
}