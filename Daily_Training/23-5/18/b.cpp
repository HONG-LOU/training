/**
 *    author:  HONG-LOU
 *    created: 2023-05-18 09:25:09
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n, k;
		std::cin >> n >> k;
		if (n * 2 < k) {
			std::cout << 0 << ' ' << n * 2 << "\n";
		}
		else {
			std::cout << n - (k - 1) / 2 << ' ' << n + k / 2 << "\n";
		}
	}  
  return 0;
}