#include "show.h"
#include <bits/stdc++.h>

void shows(std::string s) {
  int len = s.length();
  for (int i = 0; i < len + 6; i++) {
    std::cout << "=";
  }
  std::cout << "\n|  " << s << "  |\n";
  for (int i = 0; i < len + 6; i++) {
    std::cout << "=";
  }
  std::cout << "\n\n";
}

void showvs(std::vector<std::string> s) {
  int sz = (int) s.size();

  int ml = 0;
  for (int i = 0; i < sz; i++) {
    ml = std::max(ml, (int) s[i].length());
  }
  for (int i = 0; i < ml + 7; i++) {
    std::cout << "=";
  }
  for (int i = 0; i < sz; i++) {
    std::cout << "\n|";
    if (i > 0) {
      for (int j = 0; j < ml + 5; j++) {
        std::cout << '-';
      }
      std::cout << "|\n|";
    }
    int l = s[i].length();
    for (int j = 0; j < (ml + 5 - l) / 2; j++) {
      std::cout << ' ';
    }
    std::cout << s[i];
    for (int j = 0; j < (ml + 6 - l) / 2; j++) {
      std::cout << ' ';
    }
    std::cout << "|";
  }
  std::cout << "\n";
  for (int i = 0; i < ml + 7; i++) {
    std::cout << "=";
  }
  std::cout << "\n\n";
}