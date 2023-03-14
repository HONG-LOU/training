/**
 *    author:  HONG-LOU
 *    created: 2023-03-11 14:12:18
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int x = 0, y = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (a[i] > 0) {
        x++;
      }
      else {
        y++;
      }
    }
    for (int i = 0; i < x; i++) {
      std::cout << i + 1 << ' ';
    }
    for (int i = 0; i < y; i++) {
      std::cout << x - i - 1 << ' ';
    }
    std::cout << "\n";
    for (int i = 0; i < y; i++) {
      std::cout << "1 0 ";
    }
    for (int i = 0; i < n - (2 * y); i++) {
      std::cout << i + 1 << ' ';
    }
    std::cout << "\n";
  }
  return 0;
}