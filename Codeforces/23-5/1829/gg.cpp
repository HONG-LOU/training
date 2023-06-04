/**
 *    author:  HONG-LOU
 *    created: 2023-05-07 20:48:34
**/
#include <bits/stdc++.h>

const int N = 2500;
const int M = N * N;
int px[M], py[M];
long long ans[N][N];

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int cnt = 1;
  int cou = 0;
  for (int s = 0; s < N; s++) {
    for (int j = 0; j <= s; j++) {
      int i = s - j;
      if (cou < 20) {
        std::cout << i << ' ' << j << "\n";
        cou++;
      }
      px[cnt] = i;
      py[cnt] = j;
      ans[i][j] = 1ll * cnt * cnt;
      cnt++;
      if (i) ans[i][j] += ans[i - 1][j];
      if (j) ans[i][j] += ans[i][j - 1];
      if (i && j) ans[i][j] -= ans[i - 1][j - 1];
    }
  }
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::cout << ans[px[n]][py[n]] << "\n";
  }
  return 0;
}