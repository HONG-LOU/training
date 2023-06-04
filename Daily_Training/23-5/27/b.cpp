/**
 *    author:  HONG-LOU
 *    created: 2023-05-27 21:11:14
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::map<int, std::set<int>> x;
	std::vector a(m, std::vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
			a[i][j]--;
		}
	}  
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			x[a[i][j]].insert(a[i][j - 1]);
			x[a[i][j - 1]].insert(a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((int) x[i].size() != n - 1) {
			ans += (n - 1) - (int) x[i].size();
		}
	}
	std::cout << ans / 2 << "\n";
  return 0;
}