/**
 *    author:  HONG-LOU
 *    created: 2023-01-28 14:37:56
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cout << i * i << " \n"[i == n];
  }
  return 0;
}