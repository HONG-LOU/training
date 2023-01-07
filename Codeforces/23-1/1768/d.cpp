/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 18:11:14
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (a[i] > i + 1) {
        sum += a[i] - (i + 1);
      }
    }
    if (sum & 1) {
      std::cout << sum / 2 << "\n";
    }
    else {
      std::cout << sum / 2 + 1 << "\n";
    }
  }  
  return 0;
}