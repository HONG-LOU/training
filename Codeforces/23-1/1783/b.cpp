/**
 *    author:  HONG-LOU
 *    created: 2023-01-09 14:11:48
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<int>(n));
    int l = 1, r = n * n;
    int t = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = t ? l++ : r--;
        t ^= 1;
      }
      if (i & 1) {
        std::reverse(a[i].begin(), a[i].end());
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << a[i][j] << " \n"[j == n - 1];
      }
    }
  }
  return 0;
}