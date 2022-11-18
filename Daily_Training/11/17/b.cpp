/**
 *    author:  HONG-LOU
 *    created: 2022-11-17 21:13:02
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ans ^= x;
  }
  printf("%d\n", ans);
  return 0;
}