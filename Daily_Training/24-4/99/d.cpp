/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 20:16:48
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int dp[1100] = {0};
  dp[1] = 1, dp[2] = 3, dp[3] = 5;

  for (int i = 4; i <= 13; i++) {
    dp[i] = dp[i - 1] * 2 + dp[i - 3];
  }
  std::cout << dp[13];
  return 0;
}