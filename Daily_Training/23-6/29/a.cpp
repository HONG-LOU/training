/**
 *    author:  HONG-LOU
 *    created: 2023-06-29 20:08:08
**/
#include <bits/stdc++.h>

// reference to tourist

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
    const int inf = (int) 1e9;
    std::vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      int v = dp[a[i]];
      dp[a[i]] = std::max(dp[a[i]], dp[0] - i);
      dp[0] = std::max(dp[0], v + i + 1);
    }
    std::cout << dp[0] << "\n";
  }
  return 0;
}