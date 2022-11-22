/**
 *    author:  HONG-LOU
 *    created: 2022-11-22 11:14:39
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::vector<int> a(3);
  int tt;
  std::cin >> tt;
  while (tt--) {
    for (int &i : a) {
      std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    std::cout << a[1] << "\n";
  }
  return 0;
}