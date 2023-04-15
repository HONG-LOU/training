/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 13:14:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int i = 1, j = 1;
  double sum = 0;
  while (i <= n) {
    j = 1;
    while (j <= n) {
      double cnt;
      std::cin >> cnt;
      if ((i > (n / 2) + 1) && (j > (n - i + 1)) && j < (i)) {
        sum += cnt;
      }
      j++;
    }
    i++;
  }
  printf("%.1lf", sum);
  return 0;
}