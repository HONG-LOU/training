/**
 *    author:  HONG-LOU
 *    created: 2023-05-20 20:56:12
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		char c;
		std::cin >> c;
		std::string s;
		std::cin >> s;
		s += s;
		int ans = 0;
		bool ok = false;
		for (int i = 0, cnt = 0; i < n * 2; i++) {
			if (s[i] == c) {
				ok = true;
			}
			if (s[i] == 'g') {
				ans = std::max(ans, cnt);
				cnt = 0;
				ok = false;
				continue;
			}
			if (ok) cnt++;
		}
		std::cout << ans << "\n";
	}  
  return 0;
}