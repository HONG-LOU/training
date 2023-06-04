/**
 *    author:  HONG-LOU
 *    created: 2023-05-17 14:43:08
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int gcd = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == i + 1) {
        continue;
      }
      else {
        if (gcd == 0) {
          gcd = std::abs(a[i] - (i + 1));
        }
        else {
          int dis = std::abs(a[i] - (i + 1));
          gcd = std::__gcd(gcd, dis);
        }
      }
    }
    std::cout << gcd << "\n";
  }
  return 0;
}