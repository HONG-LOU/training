/**
 *    author:  HONG-LOU
 *    created: 2023-03-07 21:01:23
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cout << std::fixed << std::setprecision(20);
  int a, b;
  std::cin >> a >> b;
  if (a > b) {
    std::swap(a, b);
  }
  if (b > a * 2 / std::sqrt(3)) {
    std::cout << a * 2 / std::sqrt(3);
  }
  else {
    std::cout << std::hypot(b, a * 2 - b * std::sqrt(3));
  }
  return 0;
}