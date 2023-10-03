/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 16:35:53
**/
#include <bits/stdc++.h>

class DSU {
  public:
    std::vector<int> p;
    int n;
  
  DSU(int size) : n(size) {
    p.resize(size);
    std::iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool merge(int x, int y) {
    x = get(x);
    y = get(y);

    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  DSU d(n);
  std::vector<std::array<int, 3>> g(m);
  for (int i = 0; i < m; i++) {
    std::cin >> g[i][0] >> g[i][1] >> g[i][2];
    g[i][0]--, g[i][1]--;
  }
  std::sort(g.begin(), g.end(), [&] (auto x, auto y) {
    return x[2] < y[2];
  });
  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int x = d.get(g[i][0]);
    int y = d.get(g[i][1]);
    if (x == y) {
      continue;
    }
    d.merge(g[i][0], g[i][1]);
    cnt++;
    ans += g[i][2];
  }
  if (cnt == n - 1) {
    std::cout << ans << "\n";
  }
  else {
    std::cout << "impossible";
  }
  return 0;
}