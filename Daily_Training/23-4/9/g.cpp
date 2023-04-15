/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 20:23:10
**/
#include <bits/stdc++.h>

inline int gcd (int a, int b) {
  return a % b == 0 ? b : gcd(b, a % b);
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int cnt = a[0];
  for (int i = 1; i < n; i++) {
    cnt = gcd(cnt, a[i]);
  }
  std::cout << cnt << std::endl;
  return 0;
}