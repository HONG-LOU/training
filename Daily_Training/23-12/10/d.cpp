/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 14:26:32
**/
#include <bits/stdc++.h>
#define int long long

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i].first >> a[i].second;
      mx = std::max(mx, a[i].second);
    }
    int l = -1, r = (int) 1e9 + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      std::pair<int, int> cnt = {0, 0};
      bool ok = true;
      for (int i = 0; i < n; i++) {
        cnt = {cnt.first - mid, cnt.second + mid};
        cnt = {std::max(cnt.first, a[i].first), std::min(cnt.second, a[i].second)};
        if (cnt.first > cnt.second) {
          ok = false;
          break;
        }
      }
      if (ok) {
        r = mid;
      }
      else {
        l = mid + 1;
      }
    }
    std::cout << l << "\n";
  }
  return 0;
}