/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 17:10:52
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::map<char, int> m;
    for (int i = 0; i < 9; i++) {
      char c;
      std::cin >> c;
      m[c]++;
    }
    for (char x = 'A'; x <= 'c'; x++) {
      if (m[x] == 2) {
        std::cout << x << "\n";
        break;
      }
    }
  }
  return 0;
}