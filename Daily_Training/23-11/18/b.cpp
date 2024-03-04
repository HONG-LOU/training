/**
 *    author:  HONG-LOU
 *    created: 2023-11-18 13:02:42
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
    std::sort(a.begin(), a.end());
    long long mx = 0, mn = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (n % (i + 1) == 0) {
        mx = 0, mn = 0;
        for (int j = 0; j < n; j += (i + 1)) {
          
        }
      }
    }
  }
  return 0;
}