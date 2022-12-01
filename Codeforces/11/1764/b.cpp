/**
 *    author:  HONG-LOU
 *    created: 2022-11-28 15:47:23
**/
#include <bits/stdc++.h>

// copy

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
    int cnt = std::__gcd(a[0], a[1]);
    for (int i = 2; i < n; i++) {
      cnt = std::__gcd(a[i], cnt);
    }
    std::cout << a[n - 1] / cnt << "\n";
  }
  return 0;
}