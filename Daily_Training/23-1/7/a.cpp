/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 20:21:16
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    std::cout << s[i] << "\n";
  }
  return 0;
}