/**
 *    author:  HONG-LOU
 *    created: 2023-02-15 14:01:25
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0') {
      std::cout << '1';
    }
    else {
      std::cout << '0';
    }
  }
  return 0;
}