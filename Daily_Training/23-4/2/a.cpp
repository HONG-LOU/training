/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 20:01:05
**/
#include <bits/stdc++.h>

int have[20202] = {0};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int a, b;
  std::cin >> a >> b;

  for (int i = a; i <= b; i++) {
    int cnt = 0;
    for (int j = 1; j <= i / 2; j++) {
      if (i % j == 0) {
        cnt += j;
      }
    }
    int c = 0;
    for (int j = 1; j <= cnt / 2; j++) {
      if (cnt % j == 0) {
        c += j;
      }
    }
    if (c == i && i != cnt && !have[i] && !have[cnt]) {
      std::cout << i << ' ' << cnt << std::endl;
      have[i] = 1;
      have[cnt] = 1;
    }
  }
  return 0;
}
/*
1 20000 
220 284
1184 1210
2620 2924
5020 5564
6232 6368
10744 10856
12285 14595
17296 18416
*/
/*
1 20000
220 284
1184 1210
2620 2924
5020 5564
6232 6368
10744 10856
12285 14595
17296 18416
*/