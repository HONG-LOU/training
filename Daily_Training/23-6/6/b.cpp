/**
 *    author:  HONG-LOU
 *    created: 2023-06-06 21:20:31
**/
#include <bits/stdc++.h>

struct edge {
  int start, to;
  long long val;
} e[202020];

int f[202020];

long long ans;

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> e[i].start >> e[i].to >> e[i].val;
  }
  std::sort(e + 1, e + m + 1, [&] (auto x, auto y) {
    return x.val < y.val;
  });
  std::function<void()> kruskal = [&] () {
    for (int i = 1; i <= m; i++) {
      int u = find(e[i].start);
      int v = find(e[i].to);
      if (u == v) {
        continue;
      }
      f[u] = v;
      ans = std::max(ans, e[i].val);
      if (find(s) == find(t)) {
        return;
      }
    }
  };
  kruskal();
  std::cout << ans;
  return 0;
}