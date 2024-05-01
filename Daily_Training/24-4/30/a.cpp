/**
 *    author:  HONG-LOU
 *    created: 2024-04-30 09:34:53
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;

  std::vector<std::string> a;
  std::ifstream in;
  in.open("res.in");

  while (std::getline(in, s)) {
    std::cout << s << "\n";
    if (s.find("西北师范大学") != s.npos) {
      a.push_back(s);
    }
  }



  // for (auto c : a) {
  //   std::cout << c << "\n";
  // }
  return 0;
}