/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 22:02:45
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    long long n, s;
    std::cin >> n >> s;
    std::cout << s / (n * n) << "\n";
  }  
  return 0;
}