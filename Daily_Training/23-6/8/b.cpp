/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 16:41:51
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cnt ^= x;
  }
  std::cout << (cnt & 1 ? "Yes\n" : "No\n") << "\n";
  return 0;
}