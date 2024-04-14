/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:18:18
**/
#include "grammar.h"
class read
{
private:
  /* data */
public:
  read(/* args */);
  WG read_grammar() {
    std::cout << "Please Input Grammar File Name : ";
    std::string fs;
    std::cin >> fs;

    std::ifstream in;
    in.open(fs);

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
    return W;
  }
  ~read();
};

read::read(/* args */)
{
}

read::~read()
{
}