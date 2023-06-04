/**
 *    author:  HONG-LOU
 *    created: 2022-09-28 21:41:26
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

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  DSU d(n);
  std::vector<int> check(n, 0);
  for (int i = 0; i < m; i++) {
  	int s;
  	std::cin >> s;
  	if (s == 0) continue;
  	int fa;
  	std::cin >> fa;
  	fa -= 1;
  	for (int j = 0; j < s - 1; j++) {
  		int cnt;
  		std::cin >> cnt;
  		cnt -= 1;
  		d.merge(fa, cnt);
  	}
  }
  for (int i = 0; i < n; i++) {
  	check[d.get(i)]++;
  }
  for (int i = 0; i < n; i++) {
  	std::cout << check[d.get(i)] << " \n"[i == n - 1];
  }
  return 0;
}