/**
 *    author:  HONG-LOU
 *    created: 2023-06-03 14:38:01
**/
#include <bits/stdc++.h>

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	int n, m, t;
	std::cin >> n >> m >> t;
	std::vector<std::pair<std::string, int>> s(n);
	std::vector<int> c;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i].first;
		s[i].second = std::max(std::count(s[i].first.begin(), s[i].first.end(), '0'), std::count(s[i].first.begin(), s[i].first.end(), '1'));
	}
	std::sort(s.begin(), s.end(), [&] (std::pair<std::string, int> x, std::pair<std::string, int> y) {
		return x.second > y.second;
	});
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int z = 0, o = 0;
		for (int j = 0; j < (int) s[i].first.size(); j++) {
			if (s[i].first[j] == '0') z++;
			else o++;
		}
		if (z >= o) {
			if (t > 0) {
				ans += z;
				t--;
			}
			int cnt = 0;
			for (int j = 0; j < (int) s[i].first.size(); j++) {
				if (s[i].first[j] == '1') {
					for (int k = j; k < (int) s[i].first.size() && s[i].first[k] == '1'; k++, cnt++, j++);
					c.push_back(cnt);
					cnt = 0;
					j--;
				}
			}
		}
		else {
			if (t > 0) {
				ans += o;
				t--;
			}
			int cnt = 0;
			for (int j = 0; j < (int) s[i].first.size(); j++) {
				if (s[i].first[j] == '0') {
					for (int k = j; k < (int) s[i].first.size() && s[i].first[k] == '0'; k++, cnt++, j++);
					c.push_back(cnt);
					cnt = 0;
					j--;
				}
			}
		}
	}
	if (t <= 0) {
		std::cout << ans << "\n";
		return 0;
	}  
	std::sort(c.rbegin(), c.rend());
	for (int i = 0; i < (int) c.size() && t > 0; i++) {
		ans += c[i];
		t--;
	}
	std::cout << ans << "\n";
	return 0;
}