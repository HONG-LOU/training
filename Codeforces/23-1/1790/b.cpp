/**
 *    author:  HONG-LOU
 *    created: 2023-01-28 14:58:45
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, s, r;
    std::cin >> n >> s >> r;
    std::cout << s - r << ' ';
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1 && r; i = (i + 1) % (n - 1)) {
      a[i]++;
      r--;
    }
    for (int i = 0; i < n - 1; i++) {
      std::cout << a[i] << ' ';
    }
    std::cout << "\n";
  }
  return 0;
}