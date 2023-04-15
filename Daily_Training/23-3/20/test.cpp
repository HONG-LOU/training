/**
 *    author:  HONG-LOU
 *    created: 2023-03-19 21:15:36
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  std::sort(s.begin(), s.end(), [&] (std::string a, std::string b) {
    return (a + b) < (b + a);
  });
  for (int i = 0; i < n; i++) {
    std::cout << s[i];
  }
  return 0;
}