/**
 *    author:  HONG-LOU
 *    created: 2022-12-30 15:15:45
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::stack<int> x;
  for (int i = 1; i <= 30; i++) {
    x.push(i);
  }  
  for (int i = 1; i <= 30; i++) {
    std::cout << i << ' ' << x.top() << "\n";
    x.pop();
  }
  return 0;
}