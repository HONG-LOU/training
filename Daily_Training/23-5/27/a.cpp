/**
 *    author:  HONG-LOU
 *    created: 2023-05-27 20:40:41
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int k, n;
		std::cin >> k >> n;
		std::vector<int> a(k);
		std::iota(a.begin(), a.end(), 1);
		int la = k;
		int mx = 1;
		for (int i = 2; i < n; i++) {
			a[i] = a[i - 1] + 1;
			if () {
				a[i] += mx;
				sum += mx;
				mx++;
				sum
			}
		}
	}  
  return 0;
}