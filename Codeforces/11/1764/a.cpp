/**
 *    author:  HONG-LOU
 *    created: 2022-11-28 15:13:47
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
    std::map<int, int> mp;
    int r = 1;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      mp[a[i]]++;
      if (mp[a[i]] > 1) {
        r = i + 1;
      }
    }
    std::cout << 1 << ' ' << r << "\n";
  }
  return 0;
}