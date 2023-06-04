/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 19:46:32
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

 	int tt;
 	std::cin >> tt;
 	while (tt--) {
 		int n, s;
 		std::cin >> n >> s;
 		std::vector<int> d(n + 1, 0);
 		std::vector<int> a(n);
 		for (int i = 0; i < n; i++) {
 			std::cin >> a[i];
 			d[i + 1] = d[i];
 			if (a[i]) {
 				d[i + 1]++;
 			}
 		}
 		int ans = (int) 1e9 + 7;
 		bool ok = false;
 		for (int i = 1; i <= n; i++) {
 			int l = i, r = n;
 			while (l <= r) {
 				int mid = (l + r) / 2;
 				if (d[mid] - d[i - 1] <= s) {
 					l = mid + 1;
 				}	
 				else {
 					r = mid - 1;
 				}
 			}
 			if (d[r] - d[i - 1] == s) {
 				ok = true;
 				ans = std::min(ans, n - (r - (i - 1)));
 			}
 		}
 		std::cout << (ok ? ans : -1) << "\n";
 	}
	return 0;
}