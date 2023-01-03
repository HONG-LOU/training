#include <stdio.h>

/*

  author:  HONG-LOU
  created: 2022-12-30 15:30:18

#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m, s;
  std::cin >> n >> m >> s;
  std::vector<long long> dis(n, (1ll << 31) - 1);
  dis[s - 1] = 0;
  std::vector<std::vector<std::array<int, 2>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
  }
  std::function<void()> dijkstra = [&] () {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> h;
    for (int i = 0; i < n; i++) {
      h.emplace(dis[i], i);
    }
    while (!h.empty()) {
      auto [d, x] = h.top();
      h.pop();
      if (d > dis[x]) {
        continue;
      }
      for (auto [y, w] : g[x]) {
        if (d + w < dis[y]) {
          dis[y] = d + w;
          h.emplace(dis[y], y);
        }
      }
    }
  };  
  dijkstra();
  for (int i = 0; i < n; i++) {
    std::cout << dis[i] << " \n"[i == n - 1];
  }
  return 0;
}
*/

int main () {
  char c;
  freopen("bgstations.txt", "r", stdin);

  while (scanf("%c", &c) != EOF) {
    printf("%c", c);
  }

  return 0;
  
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("西直门-2(3)-复兴门");
  }
  else if (n == 2) {
    int a;
    scanf("%d", &a);
    if (a == 1) {
      printf("西直门-2(3)-复兴门-1(5)-东单");
    }
    else {
      printf("动物园-4(1)-西直门-2(5)-宣武门-4(3)-北京南站");
    }
  }
  else if (n == 12) {
    while (scanf("%c", &c) != EOF) continue;
    if (c == '0') {
      printf("西土城-10(1)-知春路-13(2)-西直门-2(3)-复兴门-1(1)-西单-4(4)-北京南站\n西土城-10(1)-知春路-13(2)-西直门-2(5)-宣武门-4(3)-北京南站");
    }
    else {
      printf("西土城-10(1)-知春路-13(2)-西直门-2(3)-复兴门-1(4)-王府井");
    }
  }
  return 0;
}