/**
 *    author:  HONG-LOU
 *    created: 2024-05-17 13:45:56
**/
#include <bits/stdc++.h>

inline int read(){
  int s = 0, w = 1; char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') { w = -1, ch = getchar();}}
  while(ch >= '0' && ch <= '9') { s = s * 10 + ch - '0'; ch = getchar();}
  return s * w;
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt = read();
  while (tt--) {
    int n = read();
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = read();
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      std::cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}