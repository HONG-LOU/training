/**
 *    author:  HONG-LOU
 *    created: 2022-12-16 12:45:39
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum += a[i];
    }
    long long cnt = sum;
    if (sum & 1) {
      int ans = (int) 1e9;
      for (int i = 0; i < n; i++) {
        sum = cnt;
        int s = 0;
        while (sum & 1) {
          s++;
          sum -= a[i];
          a[i] /= 2;
          sum += a[i];
        }
        ans = std::min(ans, s);
      }
      std::cout << ans << "\n";
    }
    else {
      std::cout << 0 << "\n";
    }
  }
  return 0;
}