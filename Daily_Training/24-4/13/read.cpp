/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:48:23
**/
#include "read.h"
#include "grammar.h"

void read_G() {
  std::cout << "Please Input Grammar File Name : ";
  std::string fs;
  std::cin >> fs;

  std::ifstream in;
  in.open(fs);

  std::string sentence_input;

  auto W = WG();

  while (in >> sentence_input) {
    auto cnt = grammar(sentence_input);
    W.add_grammar(cnt);
  }

  W.print_grammar();
  in.close();
}