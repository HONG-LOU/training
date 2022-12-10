/**
 *    author:  HONG-LOU
 *    created: 2022-12-10 18:54:20
**/
#include <bits/stdc++.h>

auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string a, b;
  std::cin >> a >> b;
  if ((int) a.size() < (int) b.size()) {
    std::swap(a, b);
  }  
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  std::vector<int> aa((int) a.size()), bb((int) b.size());
  for (int i = 0; i < (int) a.size(); i++) {
    aa[i] = (a[i] - '0');
  }
  for (int i = 0; i < (int) b.size(); i++) {
    bb[i] = (b[i] - '0');
    aa[i] += bb[i];
  }
  for (int i = 0; i < (int) a.size() - 2; i++) {
    aa[i + 1] += (aa[i] / 10);
    aa[i] %= 10;
  }
  if (aa[(int) aa.size() - 1] >= 10) {
    aa.push_back(aa[(int) aa.size() - 1] / 10);
    aa[(int) aa.size() - 2] %= 10; 
  }
  std::reverse(aa.begin(), aa.end());
  for (int x : aa) {
    std::cout << x;
  }
  return 0;
}