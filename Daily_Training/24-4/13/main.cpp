/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:03:00
**/
#include <bits/stdc++.h>
#include "gmenu.h"
#include "readG.h"
// #include "deduce.h"

auto main () -> int {

  read r;

  WG w;

  std::string sentence;

  while (true) {
    int c = choice();
    if (c == -1 || c == 0) {
      std::cout << "Error Input.\n";
      continue;
    }
    else if (c == 1) {
      w = r.read_grammar();
    }
    else if (c == 2) {
      w.cal_terminal();
      w.cal_non_terminal();
    }
    else if (c == 3) {
      w.split_grammar();
    }
    else if (c == 4) {
      w.cycle_check();
    }
    else if (c == 5) {
      w.print_grammar();
    }
    else if (c == 6) {
      sentence = r.read_sentence();
    }
    else if (c == 7) {
      auto ans = w.deduce(sentence);
      for (auto s : ans[0]) {
        std::cout << s;
        if (s != ans[0].back()) {
          std::cout << "==>";
        }
        else {
          std::cout << "\n\n";
        }
      }
    }
    else if (c == 9) {
      shows("Bye Bye.");
      break;
    }
  }
  
  return 0;
}