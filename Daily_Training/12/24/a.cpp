/**
 *    author:  HONG-LOU
 *    created: 2022-12-24 21:00:02
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  int z = 0;
  for (int i = 0; i < (int) s.size() - 1; i++) {
    if (s[i] == '0' && s[i + 1] == '0') {
      z++;
      i++;
    }
  }
  std::cout << (int) s.size() - z << "\n";
  return 0;
}