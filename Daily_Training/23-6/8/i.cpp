/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 17:46:45
**/
#include <bits/stdc++.h>

int a[10101], b[10101], t = 0, n, m, dp[10101] = {0}, w, v, s;

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n >> m;
  while (n--) {
    std::cin >> v >> w >> s;
    while (s--) {
      a[++t] = v;
      b[t] = w;
    }
  }
  for (int i = 1; i <= t; i++) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] = std::max(dp[j], dp[j - a[i]] + b[i]);
    }
  }
  std::cout << dp[m] << "\n";
  return 0;
}