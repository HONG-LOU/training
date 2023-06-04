/**
 *    author:  HONG-LOU
 *    created: 2023-05-06 16:43:51
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    bool ok = false;
    int mx = n;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mx = std::min(x, mx);
      if (x != n) {
        ok = true;
      }
      a[x]++;
    }
    if (!ok) {
      std::cout << -1 << "\n";
      continue;
    }
    std::cout << n - mx << "\n";
  }
  return 0;
}