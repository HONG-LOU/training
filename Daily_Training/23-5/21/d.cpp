/**
 *    author:  HONG-LOU
 *    created: 2023-05-21 11:22:52
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m;
	long long d;
	std::cin >> n >> m >> d;
	std::vector<long long> a(n);
	std::vector<long long> b(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::sort(b.begin(), b.end());
	long long ans = -1;
	for (int i = 0; i < n; i++) {
		int l = std::lower_bound(b.begin(), b.end(), a[i] - d) - b.begin();
		int r = std::upper_bound(b.begin(), b.end(), a[i] + d) - b.begin();
		if (l != r) {
			ans = std::max(ans, a[i] + b[r - 1]);
		}
	}
	std::cout << ans << "\n";
  return 0;
}