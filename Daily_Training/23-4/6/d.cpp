/**
 *    author:  HONG-LOU
 *    created: 2023-04-06 17:40:53
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::vector a(n, std::vector<int>(n));
  return 0;
}