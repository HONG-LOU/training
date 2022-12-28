/**
 *    author:  HONG-LOU
 *    created: 2022-12-28 16:19:47
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> x(n + 1, 0);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      x[i + 1] = x[i] ^ a[i];
    }
    int n2 = 1;
    while (n2 <= n) {
      n2 *= 2;
    }
    std::vector<int> cnt(n2, 0);
    long long ans = 0;
    for (int i = n; i >= 0; i--) {
      ans += n - i;
      for (int j = 0; j * j < n2; j++) {
        ans -= cnt[(j * j) ^ x[i]];
      }
      cnt[x[i]]++;
    }
    std::cout << ans << "\n";
  }
  return 0;
}