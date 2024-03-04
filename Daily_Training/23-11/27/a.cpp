/**
 *    author:  HONG-LOU
 *    created: 2023-11-29 14:33:41
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::map<long long, long long>  m;

  const int mod = 1000000007;

  std::function<long long(int)> ask = [&] (int x) {
    if (x == 0 || x == 1) {
      return (long long) 1;
    }
    if (m.find(x) != m.end()) {
      return m[x];
    }
    long long res = 0, t = x / 2;
    if (x % 2 == 1) {
      res = ask(t) * (ask(t - 1) + ask(t + 1)) % mod;
    }
    else {
      res = ask(t) * ask(t) % mod + ask(t - 1) * ask(t - 1) % mod;
    }
    m[x] = res % mod;
    return m[x];
  };
  long long a, b;
  std::cin >> a >> b;
  std::cout << (a == 0 ? 0 : ask(a - 1)) << "\n" << (b == 0 ? 0 : ask(b - 1));
  return 0;
}