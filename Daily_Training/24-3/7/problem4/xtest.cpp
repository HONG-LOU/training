/**
 *    author:  HONG-LOU
 *    created: 2024-03-15 11:57:39
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

  
  return 0;
}