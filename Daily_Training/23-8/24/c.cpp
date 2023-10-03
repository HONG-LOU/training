/**
 *    author:  HONG-LOU
 *    created: 2023-08-24 22:55:19
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
    bool ok = (a[0] == n);
    if (a[n / 2] > (n / 2) + 1 && n % 2 == 0) {
      ok = false;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}