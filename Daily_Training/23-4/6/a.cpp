/**
 *    author:  HONG-LOU
 *    created: 2023-04-06 12:28:21
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  for (int i = 1; i <= 6; i++) {
    std::vector<int> a(i);
    for (int j = 1; j <= i; j++) {
      a[j - 1] = j;
    }
    int ans = 0;
    do {
      for (int j = 1; j < i - 1; j++) {
        if ((a[j] > a[j - 1] && a[j] > a[j + 1]) || (a[j] < a[j - 1] && a[j] < a[j + 1])) {
          ans++;
        }
      }
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << i << ' ' << ans << "\n";
  }
  return 0;
}