/**
 *    author:  HONG-LOU
 *    created: 2023-01-07 14:46:07
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      pos[--a[i]] = i;
    }
    int cnt = 1;
    while (cnt < n && pos[cnt] > pos[cnt - 1]) {
      cnt += 1;
    }
    int left = n - cnt;
    std::cout << (left + k - 1) / k << "\n";
  }
  return 0;
}