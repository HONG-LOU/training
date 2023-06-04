/**
 *    author:  HONG-LOU
 *    created: 2023-05-28 17:35:14
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}  
	bool ok = false;
	std::string c = "yizhong";
	int d[3] = {-1, 0, 1};
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
	std::function<void(int, int, int, int, int)> dfs = [&] (int x, int y, int dx, int dy, int deep) {
		if (x < 0 || x >= n || y < 0 || y >= n || s[x][y] != c[deep]) {
			return;
		}
		if (deep == 6) {
			ok = true;
			return;
		}
		dfs(x + dx, y + dy, dx, dy, deep + 1);
	};
	auto change = [&] (int x, int y, int dx, int dy) {
		for (int i = 0; i < 7; i++) {
			vis[x][y] = true;
			x += dx;
			y += dy;
		}
	};
	auto sc = [&] (int x, int y) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					continue;
				}
				ok = false;
				dfs(x, y, d[i], d[j], 0);
				if (ok) {
					change(x, y, d[i], d[j]);
				}
			}
		}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'y') {
				sc(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << (vis[i][j] ? s[i][j] : '*');
		}
		std::cout << "\n";
	}
  return 0;
}