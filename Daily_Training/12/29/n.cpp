/**
 *    author:  HONG-LOU
 *    created: 2022-12-30 13:03:41
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("word.txt", "r", stdin);
  std::string s = "char s[100] = {";
  for (int i = 0; i < 100; i++) {
    std::string line;
    std::string plus;
    std::string count;
    std::cin >> line >> plus >> count;
    s += " \"";
    s += plus;
    s += " ";
    s += count;
    s += "\"";
    if (i < 99) {
      s += ",";
    }
    if (i != 0 && i % 4 == 0) {
      s += "\n";
    }
  }
  s += "};";
  std::cout << s << "\n";
  return 0;
}