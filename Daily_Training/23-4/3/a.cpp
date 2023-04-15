/**
 *    author:  HONG-LOU
 *    created: 2023-04-03 21:27:01
**/
#include <bits/stdc++.h>

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cout << "Please input number of block : ";
  std::cin >> n;

  int step = 0;

  std::function<void(int, char, char, char)> move = [&] (int n, char a, char b, char c) {
    if (n == 1) {
      step++;
      std::cout << step << ' ' << "move" << ' ' 
      << n << ' ' << "from" << ' ' << a << ' ' 
      << "to" << ' ' << c << "\n";
    }
    else {
      move(n - 1, a, c, b);
      std::cout << step << ' ' << "move" << ' ' 
      << n << ' ' << "from" << ' ' << a << ' ' 
      << "to" << ' ' << b << "\n";
      step++;
      move(n - 1, b, a, c);
    }
  };

  move(n, 'A', 'B', 'C');
  return 0;
}