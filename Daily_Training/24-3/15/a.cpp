/**
 *    author:  HONG-LOU
 *    created: 2024-03-15 12:31:17
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
  while (std::cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    DSU d(n + 1);
    while (m--) {
      int k, x;
      std::cin >> k >> x;
      for (int i = 1; i < k; i++) {
        int y;
        std::cin >> y;
        d.merge(x, y);
      }
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (d.get(i) == d.get(0)) {
        ans++;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}