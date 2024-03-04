/**
 *    author:  HONG-LOU
 *    created: 2023-12-12 11:57:03
**/
#include <bits/stdc++.h>

// 简直是昏头了 ** 2。。。。

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int ll = (s[0] == 'L'), rl = 0, lo = (s[0] == 'O'), ro = 0;
  for (int i = 1; i < n; i++) {
    rl += (s[i] == 'L');
    ro += (s[i] == 'O');
  }
  for (int i = 1; i < n; i++) {
    if (ll != rl && lo != ro) {
      std::cout << i << "\n";
      return 0;
    }
    if (s[i] == 'L') {
      ll++, rl--;
    }
    else {
      lo++, ro--;
    }
  }
  std::cout << -1 << "\n";
  return 0;
}