/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 13:27:31
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int x = 0, y = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        x--;
      }
      else if (s[i] == 'R') {
        x++;
      }
      else if (s[i] == 'U') {
        y++;
      }
      else {
        y--;
      }
      if (x == 1 && y == 1) {
        ok = true;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}