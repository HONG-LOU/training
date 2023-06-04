/**
 *    author:  HONG-LOU
 *    created: 2023-05-06 18:03:47
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
    int l = 0, r = n - 1; 
    int gcd = 0;
    while (l < r) {
      if (a[l] != a[r]) {
        int d = std::abs(a[l] - a[r]);
        if (d) {
          if (!gcd) {
            gcd = d;
          }
          else {
            gcd = std::__gcd(gcd, d);
          }
        }
      }
      l++, r--;
    }
    std::cout << gcd << "\n";
  }
  return 0;
}