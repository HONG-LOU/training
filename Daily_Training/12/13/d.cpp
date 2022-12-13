/**
 *    author:  HONG-LOU
 *    created: 2022-12-13 14:38:26
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::vector<double> x(28), y(28);
  for (int i = 0; i < 28; i++) {
    std::cin >> x[i] >> y[i];
  }
  double sum = 0;
  for (int i = 0; i < 28; i++) {
    sum += y[i];
  }
  std::cout << sum << "\n";
  double ans = 0;
  for (int i = 0; i < 28; i++) {
    ans += x[i] * y[i] / sum;
  }
  std::cout << ans << "\n";
  return 0;
}