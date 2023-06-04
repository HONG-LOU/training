/**
 *    author:  HONG-LOU
 *    created: 2023-05-23 17:01:47
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}  
	while (m--) {
		int x;
		std::cin >> x;
		int l = 0, r = n - 1;
		int ans = -1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[mid] >= x) {
				if (a[mid] == x) {
					ans = mid + 1;
				}
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		std::cout << ans << ' ';
	}
  return 0;
}