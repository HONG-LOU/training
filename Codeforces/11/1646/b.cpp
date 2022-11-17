/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 22:17:53
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }
    bool ok = false;
    std::sort(a.begin(), a.end());
    long long l = a[0] + a[1];
    long long r = a[n - 1];
    int lindex = 1;
    int rindex = n - 1;
    while (lindex < rindex) {
      if (l < r) {
        ok = true;
      }
      lindex += 1;
      rindex -= 1;
      l += a[lindex];
      r += a[rindex];
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }  
  return 0;
}