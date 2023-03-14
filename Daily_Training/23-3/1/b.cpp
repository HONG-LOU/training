/**
 *    author:  HONG-LOU
 *    created: 2023-03-06 20:47:32
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, q;
  std::cin >> n >> q;
  std::map<int, int> x;
  for (int i = 0; i < q; i++) {
    int c, y;
    std::cin >> c >> y;
    if (c == 1) {
      x[y] += 1;
    }
    else if (c == 2) {
      x[y] += 2;
    }
    else {
      if (x[y] >= 2) {
        std::cout << "Yes\n";
      }
      else {
        std::cout << "No\n";
      }
    }
  }
  return 0;
}