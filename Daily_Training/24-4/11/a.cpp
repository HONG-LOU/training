/**
 *    author:  HONG-LOU
 *    created: 2024-04-11 16:44:25
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int m, n;
  std::cin >> m >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] >= (m - 1) * n) {
      std::cout << a[i] << " \n";
    }
    
  }
  return 0;
}