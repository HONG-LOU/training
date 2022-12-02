/**
 *    author:  HONG-LOU
 *    created: 2022-12-01 12:39:56
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      cnt[a[i]]++;
    }
    long long ans = 1;
    int s = 0;
    for (auto [_, x] : cnt) {
      s += x;
      ans = std::max(ans, 1ll * s * (n - s));
    }
    if (cnt.size() == 1) {
      ans = n / 2;
    }
    std::cout << ans << "\n";
  }  
  return 0;
}