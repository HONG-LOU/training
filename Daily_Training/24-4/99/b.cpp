/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 19:48:18
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int x;
  std::cin >> x;
  std::string s = "";
  while (n) {
    int b = n % x;
    if (b >= 0 && b <= 9) {
      s += (char) (b + '0');
    }
    else {
      s += (char) (b - 10 + 'A');
    }
    n /= x;
  }
  std::reverse(s.begin(), s.end());
  std::cout << s << "\n";
  return 0;
}