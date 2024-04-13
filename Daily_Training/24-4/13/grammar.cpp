/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:23:30
**/
#include "grammar.h"

grammar::grammar() {

}

grammar::grammar(std::string s) {
  std::string left = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ':') {
      break;
    }
    left += s[i];
  }
  std::vector<std::string> right;
  right.clear();
  int index = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '=') {
      index = i + 1;
      break;
    }
  }
  std::string cnt = "";
  for (int i = index; i < s.length(); i++) {
    if (s[i] != '|') {
      cnt += s[i];
    }
    else {
      if (!cnt.empty()) {
        right.push_back(cnt);
        cnt = "";
      }
    }
  }
  if (!cnt.empty()) {
    right.push_back(cnt);
  }
  this->l = left;
  this->r = right;
}

grammar::~grammar() {

}


WG::WG()
{
  
}

WG::~WG()
{
}

void WG::add_grammar(grammar g) {
  G.push_back(g);
}

void WG::cal_non_terminal() {
  std::set<std::string> n;
  n.clear();
  for (auto c : this->G) {
    n.insert(c.get_l());
    for (auto cc : c.get_r()) {
      for (auto ch : cc) {
        if (ch >= 'A' && ch <= 'Z') {
          std::string cnt = "";
          cnt += ch;
          n.insert(cnt);
        }
      }
    }
  }
  this->non_terminal = std::vector<std::string>(n.begin(), n.end());
}

void WG::cal_terminal() {
  std::set<std::string> t;
  t.clear();
  for (auto c : this->G) {
    for (auto cc : c.get_r()) {
      for (auto ch : cc) {
        if (!(ch >= 'A' && ch <= 'Z')) {
          std::string cnt = "";
          cnt += ch;
          t.insert(cnt);
        }
      }
    }
  }
  this->terminal = std::vector<std::string>(t.begin(), t.end());
}

void WG::print_grammar() {
  for (auto c : this->G) {
    std::cout << c.get_l();
    std::cout << "=>";
    for (auto cc : c.get_r()) {
      std::cout << '[' << cc << ']' << ' ';
    }
    std::cout << "\n";
  }
  this->cal_terminal();
  this->cal_non_terminal();
  std::cout << "Terminal : ";
  for (auto c : this->terminal) {
    std::cout << c << ' ';
  }
  std::cout << "\n";
  std::cout << "Non-Terminal : ";
  for (auto c : this->non_terminal) {
    std::cout << c << ' ';
  }
  std::cout << "\n";
}