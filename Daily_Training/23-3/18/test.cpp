/**
 *    author:  HONG-LOU
 *    created: 2023-03-19 18:35:56
**/
#include <bits/stdc++.h>
#include <random>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  srand((int)time(0));  // 产生随机种子  把0换成NULL也行
  std::vector<std::string> s(1000);
  freopen("name.txt", "r", stdin);
  for (int i = 0; i < 1000; i++) {
    std::cin >> s[i];
  }
  fclose(stdin);
  freopen("2.in", "w", stdout);
  std::cout << 100 << std::endl;
  for (int i = 0; i < 100; i++) {
    int r = (rand() % 50) + 1;
    std::cout << r << ' ';
    for (int j = 0; j < r; j++) {
      int cnt = rand() % 1000;
      std::cout << s[cnt] << ' ';
    }
    std::cout << std::endl;
  }
  int q = rand() % 100;
  std::cout << q << std::endl;
  for (int i = 0; i < q; i++) {
    int cnt = rand() % 1000;
    std::cout << s[cnt] << std::endl;
  }
  fclose(stdout);
  return 0;
}