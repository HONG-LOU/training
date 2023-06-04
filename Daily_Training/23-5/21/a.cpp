/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 10:00:55
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  long long a, b;
  std::cin >> a >> b;
  std::cout << (a + b - 1) / b << "\n";
  return 0;
}