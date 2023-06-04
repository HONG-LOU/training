/**
 *    author:  HONG-LOU
 *    created: 2023-05-19 12:22:51
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin() + 1, a.end());
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << " \n"[i == n];
		}
	}  
  return 0;
}