/**
 *    author:  HONG-LOU
 *    created: 2024-03-09 17:53:31
**/
#include <bits/stdc++.h>

class DSU {
  public:
    std::vector<int> p;
    int n;
  
  DSU(int size) : n(size) {
    p.resize(size);
    std::iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool merge(int x, int y) {
    x = get(x);
    y = get(y);

    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  DSU d(n + 1);
  struct node
  {
    int u, v, w;
  }E[101010];
  
  for (int i = 1; i <= m; i++) {
    std::cin >> E[i].u >> E[i].v >> E[i].w;
  }
  std::sort(E + 1, E + m + 1, [&] (node x, node y) {
    return x.w < y.w;
  });
  long long cnt = 0;
  int total = 0;
  std::function<void()> kruskal = [&] () {
    for (int i = 1; i <= m; i++) {
      if (d.get(E[i].u) != d.get(E[i].v)) {
        d.merge(E[i].u, E[i].v);
        cnt += E[i].w;
        total += 1;
      }
    }
  };
  kruskal();
  if (total < n - 1) {
    std::cout << "impossible\n";
  }
  else {
    std::cout << cnt << "\n";
  }
  return 0;
}