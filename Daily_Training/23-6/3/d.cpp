/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 19:32:20
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
  	int n, m;
  	std::cin >> n >> m;
  	std::map<int, int> l;
  	std::map<int, int> r;
  	for (int i = 1; i <= n; i++) {
  		int x;
  		std::cin >> x;
  		if (r[x] == 0) {
  			l[x] = i;
  		}
  		r[x] = i;
  	}
  	while (m--) {
  		int u, v;
  		std::cin >> u >> v;
  		if (r[u] == 0 || r[v] == 0) {
  			std::cout << "NO\n";
  			continue;
  		}
  		std::cout << (r[v] >= l[u] ? "YES\n" : "NO\n");
  	}
  }
	return 0;
}