/**
 *    author:  HONG-LOU
 *    created: 2023-03-19 18:57:30
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::map<std::string, std::set<int>> x;
  // freopen("2.in", "r", stdin);
  // freopen("2.out", "w", stdout);
  int n;
  std::set<std::string> sett;
  sett.clear();
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
      std::string cnt;
      std::cin >> cnt;
      sett.insert(cnt);
      x[cnt].insert(i + 1);
    }
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::string cnt;
    std::cin >> cnt;
    std::cout << (int) x[cnt].size() << ' ';
    for (int ans : x[cnt]) {
      std::cout << ans << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << (int) sett.size() << "\n";
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}