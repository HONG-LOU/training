/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 20:16:24
**/
#include <bits/stdc++.h>

#define int long long

auto main() -> signed {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, d;
	std::cin >> n >> d;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}  
	std::sort(a.rbegin(), a.rend());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = (d / a[i] + 1);
		n -= cnt;
		if (n < 0) {
			break;
		}
		ans++;
	}
	std::cout << ans << "\n";
  return 0;
}