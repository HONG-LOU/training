/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 17:14:10
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    long long sum = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      sum += x;
    }
    long long sq = std::sqrt(sum);
    if (sq * sq == sum) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
  }
  return 0;
}