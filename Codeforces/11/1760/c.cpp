/**
 *    author:  HONG-LOU
 *    created: 2022-11-22 11:23:25
**/
#include <bits/stdc++.h>

// 做题做到一半被叫去做核酸的屑bro！

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      mx = std::max(mx, a[i]);
    }
    std::vector<int> b = a;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (b[i] == mx) {
        std::cout << b[i] - a[n - 2] << ' ';
      }
      else {
        std::cout << b[i] - mx << ' ';
      }
    }
    std::cout << "\n";
  }  
  return 0;
}