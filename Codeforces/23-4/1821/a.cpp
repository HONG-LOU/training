/**
 *    author:  HONG-LOU
 *    created: 2023-04-21 09:34:05
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    long long ans = 1;
    bool ok = false;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '?') {
        ok = true;
        if (i == 0) {
          ans *= 9;
        }
        else {
          ans *= 10;
        }
      }
    }
    if (ok) {
      std::cout << ans << "\n";
    }
    else {
      if (s[0] == '0') {
        std::cout << 0 << "\n";
        continue;
      }
      std::cout << 1 << "\n";
    }
  }
  return 0;
}