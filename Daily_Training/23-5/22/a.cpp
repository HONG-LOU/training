/**
 *    author:  HONG-LOU
 *    created: 2023-05-22 10:52:35
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int& i : a) {
			std::cin >> i;
		}
		std::vector<int> d(n);
		std::iota(d.begin(), d.end(), 0);
		std::sort(d.begin(), d.end(), [&] (int i, int j) {
			return a[i] < a[j];
		});
		for (int i = 0; i < n; i++) {
			std::cout << d[i] << " \n"[i == n - 1];
		}
		for (int i = 0; i < n; i++) {
			std::cout << a[d[i]] << " \n"[i == n - 1];
		}
	}  
  return 0;
}