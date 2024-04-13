/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 19:45:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int x;
  std::cin >> x;
  std::string s;
  std::cin >> s;
  long long ans = 0;
  std::reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    int cnt = 0;
    if (s[i] >= '0' && s[i] <= '9') {
      cnt = s[i] - '0';
    }
    else {
      cnt = s[i] - 'A' + 10;
    }
    ans += cnt * std::pow(x, i);
  }
  std::cout << ans << "\n";
  return 0;
}