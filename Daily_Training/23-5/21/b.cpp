/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 10:07:27
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}  
	std::string di = "snuke";
	bool ok;
	int d[3] = {-1, 0, 1};
	std::function<void(int, int, int, int, int)> dfs = [&] (int x, int y, int dx, int dy, int deep) {
		if (deep == 5) {
			ok = true;
			return;
		}
		if (x < 0 || y < 0 || x >= n || y >= m) {
			return;
		}
		if (s[x][y] != di[deep]) {
			return;
		}
		dfs(x + dx, y + dy, dx, dy, deep + 1);
	};
	int ansx = 0, ansy = 0;
	int dax = 0, day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 's') {
				for (int ii = 0; ii < 3; ii++) {
					for (int jj = 0; jj < 3; jj++) {
						if (ii == 1 && jj == 1) continue;
						ok = false;
						dfs(i, j, d[ii], d[jj], 0);
						if (ok) {
							ansx = i, ansy = j;
							dax = d[ii], day = d[jj];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << ansx + 1 << ' ' << ansy + 1 << "\n";
		ansx += dax, ansy += day;
	}
  return 0;
}