/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 21:09:06
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i] += (i + 1);
    }
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n && m >= a[i]; i++) {
      ans++;
      m -= a[i];
    }
    std::cout << ans << "\n";
  }
  return 0;
}