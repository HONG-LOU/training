/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 13:59:09
**/
#include <bits/stdc++.h>
using namespace std;
auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  int t = 1; cin >> t;
  while(t --) {
      int n, m; cin >> n >> m;
      if(n%2 && m%2) {
        cout << "1" << endl;
      } else if(n%2 && m%2 == 0) {
        cout << "0\n";
      } else if(n%2 == 0 && m%2) {
        cout << "0\n";
      } else {
        cout << m << endl;
      }
  
  }
  
  return 0;
}