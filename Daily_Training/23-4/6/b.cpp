#include <bits/stdc++.h>

int main () {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int mn = (int) 1e9;
	for (int i = 1; i < n; i++) {
		mn = std::min(mn, a[i] - a[i - 1]);
	}
  if (mn == 0) {
    std::cout << n << "\n";
  }
	std::cout << ((a[n - 1] - a[0]) / mn) + 1 << "\n";
	return 0;
}