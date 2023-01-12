/**
 *    author:  HONG-LOU
 *    created: 2023-01-11 14:37:14
**/
#include <bits/stdc++.h>

auto main() -> int {

  auto check = [&] (int x) {
    if ((x - 1) % 10 == 0) std::cout << "\n";
    while (x) {
      if ((x % 10) == 7) {
        return true;
      }
      x /= 10;
    }
    return false;
  };
  
  for (int i = 1; i <= 100; i++) {
    if ((check(i)) || i % 7 == 0) {
      std::cout << " pass";
    }
    else {
      std::cout << std::setw(5) << i;
    }
  }  
  return 0;
}