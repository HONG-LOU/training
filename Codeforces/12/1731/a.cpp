/**
 *    author:  HONG-LOU
 *    created: 2022-12-27 22:50:02
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    long long sum = 1;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      sum *= x;
    }
    sum += (n - 1);
    sum *= 2022;
    std::cout << sum << "\n";
  }  
  return 0;
}