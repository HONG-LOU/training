/**
 *    author:  HONG-LOU
 *    created: 2023-01-10 13:53:19
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> k >> n;
    int z = 1;
    int cnt = n;
    std::vector<int> a(k);
    int sum = 0;
    for (int i = k - 1; i >= 0; i--) {
      a[i] = cnt;
      cnt -= z;
      if (z > 1) sum += z;
      z++;
      if (sum >= n - k) {
        z = 1;
      }
    }
    for (int i = 0; i < k; i++) {
      std::cout << a[i] << " \n"[i == k - 1];
    }
  }  
  return 0;
}