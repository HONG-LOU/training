/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 15:52:18
**/
#include <bits/stdc++.h>

int a[101010] = {0};
std::map<int, int> x;

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int m;
  while (std::cin >> m) {
    x[m] += 1;
  }
  for (int i = 1; i <= (int) 5e4; i++) {
    a[i] = a[i - 1];
    a[i] += x[i];
  }
  std::cout << a[(int) 5e4] << "\n";
  return 0;
}