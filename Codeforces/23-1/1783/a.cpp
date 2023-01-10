/**
 *    author:  HONG-LOU
 *    created: 2023-01-08 22:49:36
 *    I am lata hahaha, continue dropping scores emmmm...
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(101);
    std::set<int> c;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      c.insert(x);
      a[x]++;
      mx = std::max(mx, a[x]);
    }
    if ((int) c.size() == 1) {
      std::cout << "NO\n";
    }
    else {
      std::cout << "YES\n";
      while (mx > 0) {
        for (int i = 100; i >= 1; i--) {
          if (a[i]) {
            a[i]--;
            std::cout << i << " ";
          }
        }
        mx--;
      }
      std::cout << "\n";
    }
  }
  return 0;
}