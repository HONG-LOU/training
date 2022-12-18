/**
 *    author:  HONG-LOU
 *    created: 2022-12-18 13:46:22
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == '1') {
        if (cnt 
      }
      else {
        std::cout << '+';
      }
    }
    std::cout << "\n";
  }
  return 0;
}