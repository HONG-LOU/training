/**
 *    author:  HONG-LOU
 *    created: 2023-01-03 13:55:08
**/
#include <bits/stdc++.h>

// tourist !!! orz orz orz

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
      std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());
    long long ans = 0;
    std::cin >> ans;
    for (int i = 0; i < n - 1; i++) {
      ans += a[i];
    }
    std::cout << ans << "\n";
  }
  return 0;
}