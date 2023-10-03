/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 20:33:29
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::stack<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (s.empty() || s.top() < x) {
      if (s.empty()) {
        std::cout << -1 << ' ';
      }
      else {
        std::cout << s.top() << ' ';
      }
      s.push(x);
    }
    else {
      while (!s.empty() && s.top() > x) {
        s.pop();
      }
      if (s.empty()) {
        std::cout << -1 << ' ';
      }
      else {
        std::cout << s.top() << ' ';
      }
      s.push(x);
    }
  }
  return 0;
}