/**
 *    author:  HONG-LOU
 *    created: 2022-09-28 21:41:26
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

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  DSU d(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    d.merge(u, v);
  }
  std::set<int> x;
  for (int i = 0; i < n; i++) {
    x.insert(d.get(i));
  }
  std::cout << (int) x.size() << "\n";
  return 0;
}