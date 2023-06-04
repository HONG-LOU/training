/**
 *    author:  HONG-LOU
 *    created: 2023-05-06 20:54:35
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
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (std::__gcd(a[i], a[j]) <= 2) {
          ok = true;
          break;
        }
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}