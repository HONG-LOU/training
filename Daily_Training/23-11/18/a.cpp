/**
 *    author:  HONG-LOU
 *    created: 2023-11-18 12:56:40
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    if (n % 3 == 0) {
      std::cout << "Second\n";
    }
    else {
      std::cout << "First" << "\n"; 
    }
  }
  return 0;
}