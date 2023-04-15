/**
 *    author:  HONG-LOU
 *    created: 2023-04-09 20:38:23
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  bool ok = false;
  int l = 0, r = 9, k = 0;
  while (s[l] != 'R') {
    l++;
  }
  while (s[r] != 'R') {
    r--;
  }
  while (s[k] != 'K') {
    k++;
  }
  if ((l < k && r > k)) {
    ok = true;
  }
  if (!ok) {
    std::cout << "No\n";
    return 0;
  }
  l = 0, r = 9;
  while (s[l] != 'B') {
    l++;
  }
  while (s[r] != 'B') {
    r--;
  }
  if (l == r % 2) {
    std::cout << "No\n";
  }
  else {
    std::cout << "Yes\n";
  }
  return 0;
}