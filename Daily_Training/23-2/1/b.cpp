/**
 *    author:  HONG-LOU
 *    created: 2023-02-15 14:17:37
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
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  DSU d(n + 1);
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    d.merge(x, x + 1);
  }
  std::map<int, std::vector<int>> g;
  for (int i = 1; i <= n; i++) {
    g[d.get(i)].push_back(i);
  }
  for (auto f : g) {
    std::sort(f.second.rbegin(), f.second.rend());
    for (auto in : f.second) {
      std::cout << in << ' ';
    }
  }
  
  return 0;
}