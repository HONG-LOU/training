/**
 *    author:  HONG-LOU
 *    created: 2023-03-26 15:51:54
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("input.txt", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  std::sort(s.begin(), s.end(), [&](auto a, auto b) {
    return a + b < b + a;
  });
  std::ofstream ms;
  ms.open("res.txt");
  for (int i = 0; i < n; i++) {
    ms << s[i];
  }
  return 0;
}