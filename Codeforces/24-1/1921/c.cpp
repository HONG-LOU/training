/**
 *    author:  HONG-LOU
 *    created: 2024-01-15 23:02:13
**/
#include <bits/stdc++.h>

#define int long long

auto main () -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, f, a, b;;
    std::cin >> n >> f >> a >> b;
    std::vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
      std::cin >> s[i];
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      int tk = s[i] - s[i - 1];
      if (b <= tk || b <= tk * a) {
        f -= b;
      }
      else {
        f -= tk * a;
      }
    }
    if (f > 0) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
  }
  return 0;
}