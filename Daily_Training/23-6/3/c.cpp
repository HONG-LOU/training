/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 14:51:20
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n = 5;
	std::vector<int> a(n);
	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		c[i] = a[i];
	}  
	std::sort(a.begin(), a.end(), [&] (int i, int j) {
		return c[i] < c[j];
	});
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}