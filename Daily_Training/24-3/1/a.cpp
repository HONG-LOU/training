/**
 *    author:  HONG-LOU
 *    created: 2024-03-01 15:48:47
**/
#include <bits/stdc++.h>

int a[101010] = {0};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, q;
  std::cin >> n >> q;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  while (q--) {
    int l = 0, r = n - 1;
    int x;
    std::cin >> x;
    while (l < r) {
      int mid = l + r >> 1;
      if (a[mid] < x)  l = mid + 1;
      else    r = mid;
    }
    if (a[l] != x) {
      printf("-1 -1\n");
      continue;
    }
    int l1 = l, r1 = n;
    while (l1 + 1 < r1) {
      int mid = l1 + r1 >> 1;
      if (a[mid] <= x)  l1 = mid;
      else    r1 = mid;
    }
    printf("%d %d\n", l, l1);
  }
  return 0;
}