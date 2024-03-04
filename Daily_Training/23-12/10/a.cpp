/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 13:43:04
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    char a, b;
    std::cin >> a >> b;
    for (char s = 'a'; s <= 'h'; s++) {
      if (s == a) {
        continue;
      }
      std::cout << s << b << "\n";
    }
    for (char s = '1'; s <= '8'; s++) {
      if (s == b) {
        continue;
      }
      std::cout << a << s << "\n";
    }
  }
  return 0;
}