/**
 *    author:  HONG-LOU
 *    created: 2023-03-28 13:45:47
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::ofstream os;
  os.open("maxx.txt");
  os << 100000 << std::endl;
  for (int i = 1; i <= 100000; i++) {
    if (i % 1000 == 0) {
      os << 'b';
    }
    else {
      os << 'a';
    }
  }
  os << std::endl << 1000 << std::endl;
  for (int i = 0; i < 999; i++) {
    os << 'a';
  }
  os << 'b';
  return 0;
}