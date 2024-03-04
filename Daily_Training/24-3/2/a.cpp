/**
 *    author:  HONG-LOU
 *    created: 2024-03-02 20:34:43
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::deque<int> q;
  for (int i = 0; i < n; i++) {
    while (q.size() && q.back() > a[i]) {
      q.pop_back();
    }
    q.push_back(a[i]);
    if (i - k >= 0 && q.front() == a[i - k]) {
      q.pop_front();
    }
    if (i >= k - 1) {
      std::cout << q.front() << ' ';
    }
  }
  std::cout << "\n";
  q.clear();
  for (int i = 0; i < n; i++) {
    while (q.size() && q.back() < a[i]) {
      q.pop_back();
    }
    q.push_back(a[i]);
    if (i - k >= 0 && a[i - k] == q.front()) {
      q.pop_front();
    }
    if (i >= k - 1) {
      std::cout << q.front() << ' ';
    }
  }
  return 0;
}