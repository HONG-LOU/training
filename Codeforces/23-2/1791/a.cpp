/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 13:21:02
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s = "codeforces";
  int tt;
  std::cin >> tt;
  while (tt--) {
    char c;
    std::cin >> c;
    bool ok = false;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == c) {
        ok = true;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}