/**
 *    author:  HONG-LOU
 *    created: 2023-03-07 20:09:25
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
  std::vector<std::pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    std::cin >> v[i].first >> v[i].second;
    v[i].first -= 1;
    v[i].second -= 1;
    d.merge(v[i].first, v[i].second);
  }
  std::map<int, std::pair<int, int>> x;
  for (int i = 0; i < n; i++) {
    x[d.get(i)].first++;  
  }
  for (int i = 0; i < m; i++) {
    x[d.get(v[i].first)].second++;
    x[d.get(v[i].second)].second++;
  }
  bool ok = true;
  for (auto p : x) {
    if (p.second.first * 2 != p.second.second) {
      ok = false;
    }
  }
  std::cout << (ok ? "Yes" : "No");
  return 0;
}