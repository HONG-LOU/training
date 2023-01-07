/**
 *    author:  HONG-LOU
 *    created: 2023-01-06 15:22:57
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("final.txt", "r", stdin);
  std::string s;
  double ans, sum;
  for (int i = 0; i < 32; i++) {
    double a, b;
    std::cin >> s >> a >> b;
    a *= b;
    ans += a;
    sum += b;
  }
  std::cout << ans / sum << "\n";
  return 0;
}