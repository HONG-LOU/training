/**
 *    author:  HONG-LOU
 *    created: 2022-11-16 19:12:00
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
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      std::cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}