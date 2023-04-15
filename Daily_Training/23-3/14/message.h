/**
 *    author:  HONG-LOU
 *    created: 2023-03-14 13:46:43
**/
#include <bits/stdc++.h>


// function about output one sentence
auto showmes (std::string s) -> void {
  int len = (int) s.size();
  int boder = len + 8;
  std::string line = "";
  for (int i = 0; i < boder; i++) {
    line += "=";
  }
  std::string ans = "";
  ans += line;
  ans += "\n";
  std::string cnt = "|   ";
  cnt += s;
  cnt += "   |\n";
  ans += cnt;
  ans += line;
  ans += "\n";
  std::cout << ans << "\n";
}


// function about output many sentence
auto showmenu (std::vector<std::string> s) -> void {
  int n = (int) s.size();
  int len = 0;
  for (int i = 0; i < n; i++) {
    len = std::max(len, (int) s[i].size());
  }
  std::string line = "";
  int boder = len + 8;
  for (int i = 0; i < boder; i++) {
    line += "=";
  }
  std::string ans = "";
  ans += line;
  ans += "\n";
  for (int i = 0; i < n; i++) {
    ans += "|   ";
    for (int j = 0; j < (len - (int) s[i].size()) / 2; j++) {
      ans += " ";
    }
    ans += s[i];
    for (int j = 0; j < (len - (int) s[i].size() + 1) / 2; j++) {
      ans += " ";
    }
    ans += "   |\n";
    if (i < n - 1) {
      ans += "|";
      for (int j = 0; j < (int) line.size() - 2; j++) {
        ans += "-";
      }
      ans += "|";
      ans += "\n";
    }
  }
  ans += line;
  ans += "\n";
  std::cout << ans << "\n";
}