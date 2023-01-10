/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 13:29:45
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    std::cout << s[0] + s[2] - '0' - '0' << "\n";
  }  
  return 0;
}