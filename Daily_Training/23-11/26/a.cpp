/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 10:12:42
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int x1, y1, x2, y2;
  auto ms = [&] (int a, int b) {
    int c = std::__gcd(a, b);
    a /= c;
    b /= c;
    if (a < 0 && b < 0) {
      a = -a;
      b = -b;
    }
    if (b < 0) {
      b = -b;
      a = -a;
    }
    std::cout << a << '/' << b << '\n';
  };
  std::cin >> x1 >> y1 >> x2 >> y2;
  if (y1 == 0) {
    std::cout << "分母不能为0!";
    return 0;
  }
  ms(x1, y1);
  if (y2 == 0) {
    std::cout << "分母不能为0!";
    return 0;
  }
  ms(x2, y2);
  if (x2 == 0) {
    std::cout << "除数不能为0!";
    return 0;
  }

  // +
  ms(x1 * y2 + x2 * y1, y1 * y2);

  // -
  ms(x1 * y2 - x2 * y1, y1 * y2);

  // * 
  ms(x1 * x2, y1 * y2);

  // /
  ms(x1 * y2, y1 * x2);
  return 0;
}