/**
 *    author:  HONG-LOU
 *    created: 2023-05-28 17:29:41
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<int> a = {0};
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		if (x) {
			a.push_back(i);
		}
	}  
	long long ans = 0;
	a.push_back(n + 1);
	for (int i = 1; i < (int) a.size() - 1; i++) {
		ans += 1ll * (a[i] - a[i - 1]) * (a[i + 1] - a[i]);
	}
	std::cout << ans << "\n";
  return 0;
}