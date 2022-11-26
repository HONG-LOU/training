/**
 *    author:  HONG-LOU
 *    created: 2022-11-26 15:37:39
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  long long a, b;
  std::cin >> a >> b;
  if (b > 0) {
    b = 1;
  }
  else {
    b = -1;
  }
  a = (a > 0 ? a : -a);
  std::cout << a * b << "\n";
  return 0;
}