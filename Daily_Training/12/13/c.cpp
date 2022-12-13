/**
 *    author:  HONG-LOU
 *    created: 2022-12-13 13:05:13
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  long long T;
  std::cin >> n >> T;
  long long sum = 0;
  std::vector<int> a(n);  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::sort(a.begin(), a.end());
  T %= sum;
  for (int i = 0; i < n; i++) {
    if (T < a[i]) {
      std::cout << i + 1 << " " << T << "\n";
      return 0;
    }
    T -= a[i];
  }
  return 0;
}