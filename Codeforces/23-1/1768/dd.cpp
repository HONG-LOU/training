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

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    DSU d(n);
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
      std::cin >> p[i];
      p[i]--;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (d.merge(i, p[i])) {
        ans += 1;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (d.get(i) == d.get(i + 1)) {
        ans -= 2;
        break;
      }
    }
    std::cout << ans << "\n";
  } 
  return 0;
}