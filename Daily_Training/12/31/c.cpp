/**
 *    author:  HONG-LOU
 *    created: 2022-12-31 10:57:52
**/
#include <bits/stdc++.h>

int a[300], b[300];

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int m, s, c;
  std::cin >> m >> s >> c;
  for (int i = 0; i < c; i++) {
    std::cin >> a[i];
    if (i > 0) {
      b[i - 1] = a[i] - a[i - 1] - 1;
    }
  }
  std::sort(b, b + c - 1, std::greater<int>());
  // for (int i = 0; i < c - 1; i++) {
  //   for (int j = i + 1; j < c - 2; j++) {
  //     if (b[j] > b[i]) {
  //       std::swap(b[i], b[j]);
  //     }
  //   }
  // }
  long long ans = a[c - 1] - a[0] + 1;
  for (int i = 0; i < m - 1; i++) {
    ans -= b[i];
  }
  std::cout << ans << "\n";
  return 0;
}