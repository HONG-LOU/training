/**
 *    author:  HONG-LOU
 *    created: 2023-12-10 16:11:55
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::vector<long long> cnt(30, 0);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        cnt[i + j + k]++;
      }
    }
  }
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    long long ans = 1;
    while (n) {
      ans*= cnt[n % 10];
      n /= 10;
    }
    std::cout << ans << "\n";
  } 
  return 0;
}