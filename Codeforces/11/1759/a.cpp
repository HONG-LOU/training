/**
 *    author:  HONG-LOU
 *    created: 2022-11-19 18:02:38
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    std::string ans = "";
    for (int i = 0; i < (int) (s.size() + 2) / 2; i++) {
      ans += "Yes";
    }
    if (ans.find(s) != std::string::npos) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
  }  
  return 0;
}