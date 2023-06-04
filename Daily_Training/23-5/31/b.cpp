/**
 *    author:  HONG-LOU
 *    created: 2023-06-04 09:06:03
**/
#include <bits/stdc++.h>

#define int long long

auto main() -> signed {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;
	int len = (int) s.size();
	auto ask = [&] (std::string t) {
		// std::reverse(t.begin(), t.end());
		int ans = 0;
		for (int i = 0; i < (int) t.size(); i++) {
			ans *= 10;
			ans += (int) (t[i] - '0');
		}
		return ans;
	};
	long long sum = 0;
	std::function<void(std::vector<std::string>, int, std::string now)> dfs = [&] (std::vector<std::string> ss, int deep, std::string now) {
		// std::cout << deep << ' ' << now << "\n";
		if (deep == len) {
			int cnt = 0;
			std::string show = "";
			for (auto t : ss) {
				cnt += ask(t), show += t, show += " ";
				// std::cout << t << " --> " << ask(t) << ' ';
			}
			sum += cnt;
			// std::cout << cnt << ' ' << show << "\n";
			return;
		}
		int l = (int) now.size();
		for (int i = 1; i <= l; i++) {
			std::string cnt = std::string(now.begin(), now.begin() + i);
			auto sss = ss;
			sss.push_back(cnt);
			dfs(sss, deep + (int) cnt.size(), std::string(now.begin() + i, now.end()));
		}
	};
	std::vector<std::string> e;
	dfs(e, 0, s);
	std::cout << sum << "\n";
	return 0;
}