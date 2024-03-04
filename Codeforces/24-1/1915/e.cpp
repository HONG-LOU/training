/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 17:45:25
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
    std::map<long long, int> m;
    long long sum = 0;
    bool ok = false;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (i & 1) {
        sum -= a[i];
      }
      else {
        sum += a[i];
      }
      if (m[sum]) {
        ok = true;
      }
      m[sum] = 1;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}