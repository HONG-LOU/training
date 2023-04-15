/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 20:08:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    for (int j = 0; j < m - 1; j++) {
      if (s[i][j] == 'T' && s[i][j + 1] == 'T') {
        s[i][j] = 'P';
        s[i][j + 1] = 'C';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << s[i] << "\n";
  }
  return 0;
}