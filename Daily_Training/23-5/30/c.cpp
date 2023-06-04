/**
 *    author:  HONG-LOU
 *    created: 2023-05-30 19:57:42
**/
#include <bits/stdc++.h>

class DSU {
	public:
		std::vector<int> p;
		int n;
	
	DSU(int size) : n(size) {
		p.resize(size);
		std::iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}

	inline bool merge(int x, int y) {
		x = get(x);
		y = get(y);

		if (x != y) {
			p[x] = y;
			return true;
		}
		return false;
	}
};

auto main() -> int {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> index(n);
	std::iota(index.begin(), index.end(), 0);
	std::sort(index.begin(), index.end(), [&] (int i, int j) {
		return a[i] < a[j];
	});
	for (int i = 0; i < n; i++) {
		std::cout << index[i] << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[index[i]] << " \n"[i == n - 1];
	}
	return 0;
}