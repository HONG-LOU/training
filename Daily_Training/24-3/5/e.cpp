/**
 *    author:  HONG-LOU
 *    created: 2024-03-05 20:03:31
**/
#include <bits/stdc++.h>
#include <fstream>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;

  std::ifstream in;

  in.open("str.txt");
  
  in >> s;

  auto tolower = [&] (std::string str) {
    for (auto &c : str) {
      if (c >= 'A' && c <= 'Z') {
        c += ('a' - 'A');
      }
    }
    return str;
  };

  s = tolower(s);

  std::vector<std::string> t;

  std::string cnt;

  while (in >> cnt) {
    cnt = tolower(cnt);

    int count = 0;
    for (auto cc : cnt) {
      if (cc != ' ') {
        count++;
      }
    }
    if (count == 0) {
      continue;
    }
    t.push_back(cnt);
  }

  int ans = 0;

  int index = 0;

  for (int i = 0; i < (int) t.size(); i++) {
    if (t[i] == s) {
      if (ans == 0) index = i;
      ans++;
    }
  }

  if (ans == 0) {
    std::cout << -1 << "\n";
  } 
  else {
    std::cout << ans << ' ' << index;
  }

  in.close();

  return 0;
}