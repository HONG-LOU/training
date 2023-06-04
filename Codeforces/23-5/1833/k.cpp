/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 20:50:12
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
 	while (m--) {
 		int sn;
 		std::cin >> sn;
 		if (sn == 0) {
 			continue;
 		}
 		int fa;
 		std::cin >> fa;
 		fa--;
 		for (int i = 0; i < sn - 1; i++) {
 			int son;
 			std::cin >> son;
 			son--;
 			d.merge(fa, son);
 		}
 	}
 	std::map<int, int> x;
 	for (int i = 0; i < n; i++) {
 		x[d.get(i)]++;
 	}
 	for (int i = 0; i < n; i++) {
 		std::cout << x[d.get(i)] << " \n"[i == n - 1];
 	}
  return 0;
}