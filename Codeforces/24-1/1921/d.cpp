/**
 *    author:  HONG-LOU
 *    created: 2024-01-15 23:09:03
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
    std::vector<int> b(m);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::vector<long long> sa(n + 1), sb(m + 1);
    for (int i = 0; i < n; i++) {
      sa[i + 1] = sa[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
      sb[i + 1] = sb[i] + b[i];
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      long long res = (sa[n] - sa[i]) - sa[i] - sb[n - i] + (sb[m] - sb[m - i]);
      ans = std::max(ans, res);
    }
    std::cout << ans << "\n";
  }
  return 0;
}