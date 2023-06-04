/**
 *    author:  HONG-LOU
 *    created: 2023-04-30 22:00:45
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 5);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}