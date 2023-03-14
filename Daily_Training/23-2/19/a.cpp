/**
 *    author:  HONG-LOU
 *    created: 2023-02-19 14:29:05
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s = "i love you i";
  std::string ans = "";
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'i') {
      ans += "you";
    }
    else {
      ans += s[i];
    }
  }
  std::cout << ans << "\n";
  return 0;
}