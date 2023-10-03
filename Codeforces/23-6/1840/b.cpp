/**
 *    author:  HONG-LOU
 *    created: 2023-06-07 13:48:31
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    long long base = 1;
    int cnt = -1;
    while (base <= n) {
      cnt++;
      base <<= 1;
    }
    std::cout << cnt << "\n";
  }
  return 0;
}