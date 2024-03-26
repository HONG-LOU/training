/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 16:23:57
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
    // x = get(x);
    // y = get(y);

    p[x] = y;
    return true;
  }
};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int m;
  std::cin >> m;

  DSU ds(26);
  for (int i = 0; i < m; i++) {
    char c, d;
    std::cin >> c >> d;
    int cc = c - 'a';
    int dd = d - 'a';
    ds.merge(cc, dd);
  }
  for (int i = 0; i < n; i++) {
    std::cout << (char) (ds.get(s[i] - 'a') + 'a');
  }
  return 0;
}