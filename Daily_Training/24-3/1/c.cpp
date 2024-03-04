/**
 *    author:  HONG-LOU
 *    created: 2024-03-01 16:38:07
**/
#include <bits/stdc++.h>

int lowbit(int x) {
  return x & (-x);
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    int res = 0;
    while (x) {
      x -= lowbit(x), res++;
    }
    std::cout << res << ' ';
  }
  return 0;
}