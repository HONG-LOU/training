/**
 *    author:  HONG-LOU
 *    created: 2023-05-25 21:09:59
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
	int d[3] = {-1, 0, 1};
	std::string v = "yizhong";
	bool ok = false;
	auto check = [&] (int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < n;
	};
	std::function<void(int, int, int, int, int)> dfs = [&] (int x, int y, int dx, int dy, int deep) {
		if (deep == 7) {
			ok = true;
			return;
		}
		if (check(x + dx, y + dy) && s[x + dx][y + dy] == v[deep]) dfs(x + dx, y + dy, dx, dy, deep + 1);
	};
	std::vector vis(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'y' && !vis[i][j]) {
				ok = false;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						if (k == l) continue;
						dfs(i, j, d[k], d[l], 1);
						if (ok) {
							int cx = i, cy = j;
							for (int now = 0; now < 7; now++) {
								vis[cx][cy] = true;
								cx += d[k], cy += d[l];
							}
							ok = false;
						}
					}
				}
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