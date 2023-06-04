/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 21:25:38
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;
	std::vector<std::set<int>> e(n);
	std::vector<int> deg(n);
	int ans = n;
	while (q--) {
		int t;
		std::cin >> t;
		if (t == 1) {
			int u, v;
			std::cin >> u >> v;
			u--, v--;
			ans -= !deg[u]++;
			ans -= !deg[v]++;
			e[u].insert(v);
			e[v].insert(u);
		} else {
			int u;
			std::cin >> u;
			u--;
			ans += (deg[u] > 0);
			deg[u] = 0;
			for (auto v : e[u]) {
				ans += !--deg[v];
				e[v].erase(u);
			}
			e[u].clear();
		}
		std::cout << ans << "\n";
	}  
  return 0;
}