
#include "gmenu.h"
#include <bits/stdc++.h>


int choice () {
  std::vector<std::string> me;
  me.push_back("1.Input Grammar File.");
  me.push_back("2.Finding Terminators And Non-terminators.");
  me.push_back("3.Split Grammar.");
  me.push_back("4.Compact Grammar.");
  me.push_back("5.Print Grammar.");
  me.push_back("6.Input Sentence For Deduce.");
  me.push_back("7.Deduce Sentence Use Grammar.");
  me.push_back("8.Construct Syntax Tree.");
  me.push_back("9.Exit System.");

  showvs(me);

  std::string s;
  std::cin >> s;
  std::cout << "\n";
  if (s.length() != 1) {
    return -1;
  }
  

  int c = s[0] - '0';

  if (c < 0 || c > 9) {
    return 0;
  }

  return c;
}