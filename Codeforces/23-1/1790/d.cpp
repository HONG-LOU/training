/**
 *    author:  HONG-LOU
 *    created: 2023-01-28 17:01:10
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int, int> x;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      x[a[i]]++;
    }
    std::sort(a.begin(), a.end());
    int cnt = 0;
    int mn = 0;
    for (auto u : x) {
      
    }
  }
  return 0;
}