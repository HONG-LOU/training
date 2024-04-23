/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:18:18
**/
#include "grammar.h"
#include "show.h"
#include <bits/stdc++.h>
class read {
private:
  
public:
  read();
  WG read_grammar() {
    shows("Please Input Grammar File Name.");
    std::string fs;
    std::cin >> fs;
    std::cout << "\n";
    std::ifstream in;
    in.open(fs);

    if (!in) {
      shows("No Such File In Directory.");
      return WG();
    }
    
    std::string sentence_input;
    auto W = WG();

    bool startok = true;
    while (in >> sentence_input) {
      auto cnt = grammar(sentence_input);
      if (startok) {
        startok = false;
        W.set_start(cnt.get_l());
      }
      W.add_grammar(cnt);
    }
    in.close();
    shows("Grammar File Read Completed.");
    return W;
  }

  std::string read_sentence() {
    shows("Please Input Sentece File Name.");
    std::ifstream ins;
    std::string fs;
    std::cin >> fs;
    std::cout << "\n";
    ins.open(fs);
    if (!ins) {
      shows("No Such File In Directory.");
      return "";
    }
    std::string sentence;
    ins >> sentence;
    shows("Sentence File Read Completed.");
    return sentence;
  }
  ~read();
};

read::read(/* args */)
{
}

read::~read()
{
}