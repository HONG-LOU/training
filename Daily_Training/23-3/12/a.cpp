/**
 *    author:  HONG-LOU
 *    created: 2023-03-12 18:46:24
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  for (int i = 0; i < (int) s.size(); i += 2) {
    std::cout << s[i + 1] << s[i];
  }
  return 0;
}