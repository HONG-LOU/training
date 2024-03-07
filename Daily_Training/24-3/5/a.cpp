#include <bits/stdc++.h>

auto main() -> int {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}

