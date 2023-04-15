/**
 *    author:  HONG-LOU
 *    created: 2023-04-06 16:49:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i < n; i++) {
      std::cin >> a[i];
    }
    a[0] = a[n] = (int) 1e9;
    for (int i = 1; i <= n; i++) {
      std::cout << std::min(a[i], a[i - 1]) << " \n"[i == n];
    }
  }
  return 0;
}