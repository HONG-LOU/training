/**
 *    author:  HONG-LOU
 *    created: 2022-11-26 16:36:07
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::vector<long long> a;
  a.push_back(1);
  int cnt = 1;
  while (a.back() <= (long long) 1e18) {
    a.push_back(a.back() + cnt);
    cnt += 4;
  }
  int q;
  std::cin >> q;
  while (q--) {
    long long k;
    std::cin >> k;
    std::cout << std::lower_bound(a.begin(), a.end(), k) - a.begin() << "\n";
  }
  return 0;
}