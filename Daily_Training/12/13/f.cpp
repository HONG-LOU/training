/**
 *    author:  HONG-LOU
 *    created: 2022-12-14 20:47:47
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  
  const int n = 28;
  std::vector<double> x(n), y(n);
  double sum = 0;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
    ans += (x[i] * y[i]);
    sum += y[i]; 
  }  
  ans /= sum;
  std::cout << ans << std::endl;
  return 0;
}