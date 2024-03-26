/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 20:35:44
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

  int n, m, k;
  std::cin >> n >> m >> k;
  DSU d(n);
  std::vector<std::array<int, 3>> g(m);
  for (int i = 0; i < m; i++) {
    std::cin >> g[i][0] >> g[i][1] >> g[i][2];
  }
  std::sort(g.begin(), g.end(), [&] (std::array<int, 3> x, std::array<int, 3> y) {
    return x[2] < y[2];
  });
  int kk = k;
  k = n;
  long long cnt = 0;
  for (int i = 0; i < m && k > kk; i++) {
    if (d.get(g[i][0]) != d.get(g[i][1])) {
      cnt += g[i][2];
      k--;
      d.merge(g[i][0], g[i][1]);
    }
  }
  if (k != kk) {
    std::cout << "No Answer\n";
  }
  else {  
    std::cout << cnt << "\n";
  }
  return 0;
}