/**
 *    author:  HONG-LOU
 *    created: 2023-12-06 18:51:47
**/
#include <bits/stdc++.h>

char s[26][7][5];

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 7; j++) {
      for (int k = 0; k < 5; k++) {
        std::cin >> s[i][j][k];
      }
    }
  }

  std::vector<std::vector<char>> st;
  std::string cnt;
  std::cin >> cnt;
  int sz = 0;
  st.push_back(std::vector<char>());
  for (int i = 0; i < (int) cnt.size(); i++) {
    if (cnt[i] > 'Z' || cnt[i] < 'A') {
      if (i != (int) cnt.size() - 1) {
        st.push_back(std::vector<char>());
      }
    }
    else {
      st.back().push_back(cnt[i]);
    }
  }
  int len = (int) st.size();
  for (int i = 0; i < len; i++) {
    
  }
  return 0;
}