/**
 *    author:  HONG-LOU
 *    created: 2024-01-17 19:41:25
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i][0] >> a[i][1];
      a[i][2] = a[i][1] - a[i][0];
    }
    std::sort(a.begin(), a.end(), [&] (auto x, auto y) {
      return x[2] < y[2];
    });
    for (int i = 0; i < n; i++) {
      std::cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << "\n";
    }
    std::map<int, int> m;
    int ans = 0;
  }
  return 0;
}