/**
 *    author:  HONG-LOU
 *    created: 2023-02-12 11:59:09
 **/
#include <bits/stdc++.h>

auto main() -> int
{
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--)
  {
    int n;
    std::cin >> n;
    int nn = 2 * n;
    if (n & 1)
    {
      std::cout << "YES" << std::endl;
      long long b = 2 * n - n / 2; // s/n-n/2-1
      long long a = 1;
      for (int i = 1; i <= (n + 1) / 2; i++)
      { // 遍历n范围内的所有奇数，构成第1个到中间的数对
        std::cout << a << " " << b << std::endl;
        a += 2;
        b--;
      }
      a = 2, b = 2 * n; // 2和s/n+1-2
      for (int i = 1; i <= n / 2; i++)
      { // 遍历n范围内所有偶数
        std::cout << a << " " << b << std::endl;
        a += 2;
        b--;
      }
    }
    else
    {
      std::cout << "no\n";
    }
  }
  return 0;
}