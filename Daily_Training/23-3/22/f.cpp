/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 15:35:32
**/
#include <bits/stdc++.h>

using namespace std;

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    long long n, m;
    std::cin >> n >> m;
    if (m > n) {
      if (n & 1) {
        std::cout << 1 << std::endl;
      }
      else {
        std::cout << 0 << std::endl;
      }
      continue;
    }
    if (m == 1) {
      if (n & 1) {
        std::cout << 1 << std::endl;
      }
      else {
        std::cout << 0 << std::endl;
      }
      continue;
    }
    if (m == n) {
      if (n & 1) {
        std::cout << 1 << std::endl;
      }
      else {
        std::cout << m << std::endl;
      }
      continue;
    }
    // int cnt = m;
    // while (m * cnt <= n) {
    //   m *= cnt;
    // }
    // std::cout << n << ' ' << m << std::endl;
    if(n%2 && m%2) {
      cout << "1" << endl;
    } else if(n%2 && m%2 == 0) {
      int t = n%(m + 1);
      if(t == 0) {
        cout << "0" << endl;
      } else if(t == m) {
        cout << m << endl;
      } else if(t & 1) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if(n%2 == 0 && m%2) {
      cout << 0 << std::endl;
    } else {
      int t = n%(m + 1);
      if(t == 0) {
        cout << 1 << endl;
      } else if(t == m) {
        cout << m << endl;
      } else if(t & 1) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
