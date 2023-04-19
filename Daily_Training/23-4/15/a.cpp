/**
 *    author:  HONG-LOU
 *    created: 2023-04-15 20:03:11
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') {
      ok = false;
      break;
    }
    if (s[i] == 'o') {
      ok = true;
    }
  }
  std::cout << (ok ? "Yes\n" : "No\n");
  return 0;
}