/**
 *    author:  HONG-LOU
 *    created: 2022-11-19 18:11:49
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, s;
    std::cin >> n >> s;
    std::map<int, bool> c;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mx = std::max(mx, x);
      c[x] = true;
    }
    for (int i = 1; i <= mx; i++) {
      if (!c[i]) {
        s -= i;
      }
    }
    while (s > 0) {
      mx++;
      s -= mx;
    }
    std::cout << (s == 0 ? "YES\n" : "NO\n");
  }  
  return 0;
}