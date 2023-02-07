/**
 *    author:  HONG-LOU
 *    created: 2023-02-07 14:05:14
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
    long long sum = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (a[i] < 0) {
        odd++;
        a[i] = -a[i];
      }
      sum += a[i];
    }
    if (odd & 1) {
      sum -= *std::min_element(a.begin(), a.end()) * 2;
    }
    std::cout << sum << "\n";
  }
  return 0;
}