/**
 *    author:  HONG-LOU
 *    created: 2023-03-07 19:46:56
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> c(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i * j <= n; j++) {
      c[i * j]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (long long) c[i] * c[n - i];
  }
  std::cout << ans << "\n";
  return 0;
}