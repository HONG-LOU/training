/**
 *    author:  HONG-LOU
 *    created: 2024-02-14 19:41:19
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int x;
    std::cin >> x;
    int a = 1, b = 1, c = x - 2;
    while (c > 26) {
      b += 1;
      c -= 1;
    }
    while (b > 26) {
      a += 1;
      b -= 1;
    }
    char sa = a + 'a' - 1;
    char sb = b + 'a' - 1;
    char sc = c + 'a' - 1;
    std::cout << sa << sb << sc << "\n";
  }
  return 0;
}