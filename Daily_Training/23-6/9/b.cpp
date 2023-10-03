/**
 *    author:  HONG-LOU
 *    created: 2023-06-10 14:09:57
**/
#include <bits/stdc++.h>

std::string to(int x) {
  std::string ans = "";
  while (x) {
    ans += (char) (x % 10) + '0';
    x /= 10;
  }
  std::reverse(ans.begin(), ans.end());
  return ans;
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string a;
  for (int i = 1; i <= 2023; i++) {
    a += to(i);
  }
  std::cout << (int) a.size() << "\n";
  std::string s;
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] == '2') {
      s += "2";
    }
    if (a[i] == '0') {
      s += "0";
    }
    if (a[i] == '3') {
      s += "3";
    }
  }
  std::cout << (int) s.size() << "\n";
  int ans = 0;
  for (int i = 0; i < 1760; i++) {
    if (s[i] == '2') {
      for (int j = i + 1; j < 1760; j++) {
        if (s[j] == '0') {
          for (int k = j + 1; k < 1760; k++) {
            if (s[k] == '2') {
              for (int l = k + 1; l < 1760; l++) {
                if (s[l] == '3') {
                  ans++;
                }
              }
            }
          }
        }
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}