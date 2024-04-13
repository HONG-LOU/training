/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 19:51:54
**/
#include <bits/stdc++.h>

std::string b[5] = {
"XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX",
"X.X...X...X...X.X.X.X...X.....X.X.X.X.X",
"X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX",
"X.X...X.X.....X...X...X.X.X...X.X.X...X",
"XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX"
};

char p[10][5][4] = {0};

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  // std::cout << b[0].size() << "\n";

  for (int i = 0; i < 39; i += 4) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 3; k++) {
        p[i / 4][j][k] = b[j][i + k];
      }
    }
  }

  std::string ans[5];

  for (int i = 0; i < s.length(); i++) {
    int cnt = s[i] - '0';
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 3; k++) {
        ans[j] += p[cnt][j][k];
        
      }
      ans[j] += (i < (int) s.size() - 1) ? "." : "";
    }
  }

  for (int i = 0; i < 5; i++) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}