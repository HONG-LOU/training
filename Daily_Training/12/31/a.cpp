/**
 *    author:  HONG-LOU
 *    created: 2022-12-31 09:34:08
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  long long a, b, x;
  std::cin >> a >> b >> x;
  int ans = 0;
  for (long long i = 1; i * i * i <= b; i++) {
    long long cnt = i * i * i;
    if (cnt >= a && cnt <= b && cnt % x == 0) {
      ans++;
    }
  }
  std::cout << ans;
  return 0;
}