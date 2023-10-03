/**
 *    author:  HONG-LOU
 *    created: 2023-06-10 14:00:16
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s = "";
  long long f[4] = {0};
  for (int i = 1; i <= 2023; i++) {
    std::string cnt = std::to_string(i);
    for (int j = 0; j < (int) cnt.size(); j++) {
      char c = cnt[j];
      if (c == '2') {
        f[0]++;
        f[2] += f[1];
      }
      else if (c == '0') {
        f[1] += f[0];
      }
      else if (c == '3') {
        f[3] += f[2];
      }
    }
  }
  std::cout << f[3] << "\n";
  return 0;
}