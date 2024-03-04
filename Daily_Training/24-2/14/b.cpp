/**
 *    author:  HONG-LOU
 *    created: 2024-02-14 19:48:10
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    long long sum = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }
    int avg = sum / n;
    long long cnt = 0;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      cnt += a[i];
      if (cnt < (long long) avg * (i + 1)) {
        ok = 0;
        break;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}