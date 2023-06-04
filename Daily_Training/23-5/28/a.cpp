/**
 *    author:  HONG-LOU
 *    created: 2023-05-28 17:24:04
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> s(n + 1, 0);
	std::map<int, int> x;
	x[0] = 1;
	int res = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		if (i) {
			s[i] = s[i - 1] + a[i];
		}
		if (x[sum - 1]) {
			res += x[sum - 1];
		}
		x[sum] += 1;
	}
	std::cout << res << "\n";
  return 0;
}