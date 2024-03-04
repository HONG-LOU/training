/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 15:50:57
**/
#include <bits/stdc++.h>

int cn[11][1010] = {0};
int ix[11] = {0};
int n;
int mn = (int) 1e9;

int used[1010] = {0};

int cnt[10] = {0};

void dfs (int deep, int sum) {
  if (deep == n) {
    mn = std::min(mn, sum);
    return;
  }
  for (int i = 0; i < ix[deep]; i++) {

    if (!used[cn[deep][i]]) {
      used[cn[deep][i]] = 1;
      dfs(deep + 1, sum + cn[deep][i]);
      used[cn[deep][i]] = 0;
    }
  }
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto check = [&] (int x) {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return 0;
      }
    }
    return 1;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= a[i]; j++) {
      if (a[i] % j == 0 && check(j)) {
        cn[i][ix[i]++] = j;
      }
    }
  }
  dfs(0, 0);
  if (mn == (int) 1e9) {
    mn = -1;
  }
  std::cout << mn;
  
  return 0;
}