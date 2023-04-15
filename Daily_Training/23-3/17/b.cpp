/**
 *    author:  HONG-LOU
 *    created: 2023-03-17 10:51:26
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

  int n, m, s;
  std::cin >> n >> m >> s;
  DSU d(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    d.merge(u, v);
  }
  for (int i = 0; i < s; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    if (d.get(u) == d.get(v)) {
      std::cout << "Yes\n";
    }
    else {
      std::cout << "No\n";
    }
  }
  return 0;
}