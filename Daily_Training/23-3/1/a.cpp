/**
 *    author:  HONG-LOU
 *    created: 2023-03-06 20:40:33
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] <= 'z' && s[i] >= 'a') {
      std::cout << (char) (s[i] - ('a' - 'A'));
    }
    else {
      std::cout << s[i];
    }
  }
  return 0;
}