/**
 *    author:  HONG-LOU
 *    created: 2024-03-02 20:43:49
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    ans ^= x;
  }
  std::cout << ans << "\n";
  return 0;
}