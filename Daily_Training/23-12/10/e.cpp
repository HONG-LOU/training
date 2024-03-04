/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 16:20:52
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    long long ans = 1;
    while (n) {
      int x = n % 10;
      ans *= (x + 1) * (x + 2) / 2;
      n /= 10;
    }
    std::cout << ans << "\n";
  }
  return 0;
}