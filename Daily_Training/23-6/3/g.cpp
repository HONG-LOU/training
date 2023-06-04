/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 20:04:02
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::map<int, bool> used;
		std::cout << 2 << "\n";
		for (int i = 1; i <= n; i++) {
			if (used[i]) {
				continue;
			}
			std::cout << i << ' ';
			if (used[i * 2] || i * 2 > n) {
				continue;
			}
			std::cout << i * 2 << ' ';
			used[i * 2] = true;
		}
		std::cout << "\n";
	}  
	return 0;
}