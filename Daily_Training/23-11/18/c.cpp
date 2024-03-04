/**
 *    author:  HONG-LOU
 *    created: 2023-11-18 13:16:32
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
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int f = 0, s = 1;
    long long sum = a[0];
    long long mx = a[0];
    while (s < n) {
      if ((a[s] + a[s - 1]) & 1 || f == s) {
        sum += a[s];
        s++;
      }
      else {
        sum -= a[f];
        f = f + 1;
      }
      std::cout << sum << " \n"[s == n];
      mx = std::max(mx, sum);
    }
    std::cout << mx << "\n";
  }
  return 0;
}