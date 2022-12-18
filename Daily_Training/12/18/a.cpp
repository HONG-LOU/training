/**
 *    author:  HONG-LOU
 *    created: 2022-12-18 09:44:30
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  switch (n) {
    case 1:
    case 2: std::cout << '5';
    case 3:
    case 4: std::cout << '6'; break;
    default: std::cout << '7';
  } 
  return 0;
}