/**
 *    author:  HONG-LOU
 *    created: 2022-11-19 18:21:05
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    long long l, r, x;
    std::cin >> l >> r >> x;
    long long a, b;
    std::cin >> a >> b;
    if (a == b) {
      std::cout << 0 << "\n";
      continue;
    }
    long long rx = a + x;
    int la = 0;
    long long ca = a;
    bool bl = true;
    if (a > b) {
      std::swap(a, b);
    }
    while (ca < rx) {
      la += 1;
      ca += x;
      if (ca > r) {
        bl = false;
        break;
      }
    }
    if (ca != rx) {
      la += 1;
    }
    if (!bl) {
      std::cout << -1 << "\n";
    }
    else if (bl) {
      std::cout << la + 1 << "\n";
    }
  }  
  return 0;
}