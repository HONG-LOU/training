/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 18:59:37
**/
#include <bits/stdc++.h>

void check (long long x) {
  long long i = 1;
  if (x == 2) {
    std::cout << "Yes\n";
    return;
  }
  if (x == 1) {
    std::cout << "No\n";
    return;
  }
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  while (n--) {
    long long x;
    std::cin >> x;
    check(x);
  }
  return 0;
}