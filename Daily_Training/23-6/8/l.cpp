/**
 *    author:  HONG-LOU
 *    created: 2023-06-08 21:32:22
**/
#include <bits/stdc++.h>

long long ans = 0;
long long f[15][2050][2050] = {0};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  f[0][0][0] = 1;
  for (int i = 1; i <= 10; i++) {
    for (int z = 0; z <= 2022; z++) {
      for (int k = 0; k <= 2022; k++) {
        if (k > z) {
          continue;
        }
        if (k && z >= k) {
          f[i][z][k] += f[i - 1][z - k][k - 1];
        }
        if (z && k) {
          f[i][z][k] += f[i][z - 1][k - 1];
        }
      }
    }
  }
  for (int i = 0; i <= 2022; i++) {
    ans += f[10][2022][i];
  }
  std::cout << ans << "\n";
  return 0;
}