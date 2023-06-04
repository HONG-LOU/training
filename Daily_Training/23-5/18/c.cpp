/**
 *    author:  HONG-LOU
 *    created: 2023-05-18 11:23:02
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> bt(n);
  for (int i = 0; i < n; i++) {
  	int t, b;
  	std::cin >> t >> b;
  	bt[i] = std::make_pair(b, t);
  }
  std::sort(bt.rbegin(), bt.rend());
  long long ans = 0;
  long long sum = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
  for (int i = 0; i < n; i++) {
  	if ((int) Q.size() == k) {
  		sum -= Q.top();
  		Q.pop();
  	}
  	Q.push(bt[i].second);
  	sum += bt[i].second;
  	ans = std::max(ans, sum * bt[i].first);
  }
  std::cout << ans << "\n";
  return 0;
}