/**
 *    author:  HONG-LOU
 *    created: 2024-04-09 18:09:36
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  int n = (int) s.size();
  // std::vector<char> c(n);
  // for (int i = 0; i < n; i++) {
  //   c[i] = (char) (i + 'a');
  // }
  // int cnt = 1;
  // do {
  //   std::string str(c.begin(), c.end());
  //   std::cout << cnt++ << ' ' << str << "\n";
  // } while (std::next_permutation(c.begin(), c.end()));


  // std::vector<long long> g(100);
  // g[1] = 26;
  // for (int i = 1; i <= 10; i++) {
  //   g[i] *= 26;
  // }


  int a[101] = {0};
  a[1] = 1;
  for (int i = 2; i <= 11; i++) {
    a[i] = a[i - 1] * i;
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << a[i] << " \n"[i == n];
  // }

  int b[10] = {0};
  for (int i = n - 1; i >= 1; i--) {
    b[n - i] = a[i];
  }

  // for (int i = 1; i <= n - 1; i++) {
  //   std::cout << b[i] << " \n"[i == n - 1];
  // }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    // for (int )
    int c = 0;
    for (int j = i + 1; j < n; j++) {
      if (s[j] < s[i]) {
        c++;
      }
    }
    // std::cout << c << ' ' << b[i + 1] << "\n";
    ans += c * b[i + 1];
  }
  std::cout << ans << "\n";
  return 0;
}