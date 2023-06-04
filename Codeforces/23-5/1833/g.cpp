/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 21:07:24
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector a(n, std::vector<int>(n - 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				std::cin >> a[i][j];
			}
		}
		std::map<int, int> x;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			x[a[i][0]]++;
			if (x[a[i][0]] == n - 1) {
				ans = a[i][0];
			}
		}
		std::cout << ans << ' ';
		for (int i = 0; i < n; i++) {
			if (a[i][0] != ans) {
				for (int j = 0; j < n - 1; j++) {
					std::cout << a[i][j] << " \n"[j == n - 2];
				}
				break;
			}
		}
	}  
  return 0;
}