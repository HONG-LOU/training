/**
 *    author:  HONG-LOU
 *    created: 2023-05-30 18:24:15
**/
#include <bits/stdc++.h>

auto main() -> int {
	// std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> d(n);
	for (int i = 0; i < n; i++) {
		std::cin >> d[i];
	}
	int ans = (int) 1e9;
	std::vector<bool> vis(n, false);
	std::function<void(int, int)> dfs = [&] (int cnt, int step) {
		std::cout << cnt << ' ' << step << "\n";
		if (cnt == b) {
			ans = std::min(ans, step);
			return;
		}
		if (step >= n) {
			return;
		}
		vis[cnt] = true;
		dfs(cnt + d[step], step + 1);
		if (cnt - d[step] > 0) dfs(cnt - d[step], step + 1);
	};
	dfs(a, 0);
	std::cout << ans << "\n";
	return 0;
}