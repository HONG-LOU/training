/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 20:01:53
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<long long> x(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }
  for (int i = 1; i < n; i++) {
    if (x[i] - x[i - 1] <= m) {
      std::cout << x[i] << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}