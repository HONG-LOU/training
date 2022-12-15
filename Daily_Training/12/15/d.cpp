/**
 *    author:  HONG-LOU
 *    created: 2022-12-15 18:02:09
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, K, d;
  std::cin >> n >> K >> d;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector dp(n + 1, std::vector(K + 1, std::vector<long long>(d, -1)));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < K + 1; j++) {
      for (int k = 0; k < d; k++) {
        if (dp[i][j][k] == -1) {
          continue;
        }
        dp[i + 1][j][k] = std::max(dp[i + 1][j][k], dp[i][j][k]);
        if (j != K) {
          dp[i + 1][j + 1][(k + a[i]) % d] = std::max(dp[i + 1][j + 1][(k + a[i]) % d], dp[i][j][k] + a[i]);
        }
      }
    }
  }
  std::cout << dp[n][K][0] << "\n";
  return 0;
}