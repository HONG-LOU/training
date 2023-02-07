/**
 *    author:  HONG-LOU
 *    created: 2022-09-28 21:41:26
**/
#include <bits/stdc++.h>

struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
};

int ask (int x) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    DSU dsu(n + 1);
    while (q--) {
      int c;
      std::cin >> c;
      if (c == 2) {
        int x;
        std::cin >> x;
        std::cout << a[x - 1] << "\n";
      }
      else {
        int l, r;
        std::cin >> l >> r;
        int x = dsu.leader(l - 1);
        while (x < r) {
          a[x] = ask (a[x]);
          if (a[x] < 10) {
            dsu.merge(x + 1, x);
          }
          x = dsu.leader(x + 1);
        }
      }
    }
  }
  return 0;
}