/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 14:45:59
**/
#include <bits/stdc++.h>
using namespace std;

void solve(std::string s) {
  int n = s.size();
  int i = 0, j = i + n - 1;
  while(i < n) {
    int ii = i, jj = j;
    int ok = 1;
    while(ii < jj) {
      if(s[ii] != s[jj]) {
        ok = 0;
      }
      ii++, jj --;
    }
    if(ok) {
      std::cout << "YES ";
      cout << ((i + j)/2)%n << endl;
      return;
      break;
    } else {
      i ++, j ++;
      s += s[i - 1];
    }
  }
  std::cout << "NO\n";
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  while (std::cin >> s) {
    solve(s);
  }
  return 0;
}