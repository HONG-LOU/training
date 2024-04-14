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
        if (cnt == left) {
          cnt = "";
          continue;
        }
        right.push_back(cnt);
        cnt = "";
      }
    }
  }
  if (!cnt.empty() && cnt != left) {
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

bool WG::is_terminal(std::string s) {
  for (auto c : terminal) {
    if (c == s) {
      return true;
    }
  }
  return false;
}

bool WG::is_non_terminal(std::string s) {
  for (auto c : non_terminal) {
    if (c == s) {
      return true;
    }
  }
  return false;
}

bool WG::first_check() {
  int sz = G.size();
  std::map<std::string, bool> dervied;
  std::vector<std::string> checked_N;

  dervied.clear();

  dervied[get_start()] = true;

  std::queue<std::string> derive;
  derive.push(get_start());

  while (!derive.empty()) {
    auto new_be_derived = derive.front();
    checked_N.push_back(new_be_derived);
    derive.pop();
    for (auto s : G) {
      if (s.get_l() == new_be_derived) {
        for (auto r : s.get_r()) {
          for (auto ch : r) {
            std::string cch = "";
            cch += ch;
            if (!dervied[cch] && is_non_terminal(cch)) {
              derive.push(cch);
              dervied[cch] = true;
            }
          }
        }
      }
    }
  }

  WG ng;
  ng.set_start(get_start());

  // std::vector<grammar> nG;

  for (auto c : G) {
    if (dervied[c.get_l()]) {
      ng.add_grammar(c);
    }
  }

  ng.cal_non_terminal();
  ng.cal_terminal();

  *this = ng;
  return (int) getG().size() == sz;
}

// 判别条件2
bool WG::second_check() {
  int sz = (int) G.size();
  std::map<grammar, bool> is_next; // 用来判断这句语法是否已经推导过
  is_next.clear();

  std::vector<grammar> value; // 存储可以推导到的语法

  std::map<std::string, bool> is_derived; // 判断当前符号是否可以推导到

  std::queue<std::string> sderive; // 队列存储当前推导的符号

  // 遍历所有语法找到右部只包含终结符的语法
  for (auto c : G) {
    for (auto sc : c.get_r()) {
      bool is_all_teiminal = true;
      for (auto ch : sc) {
        std::string cch = "";
        cch += ch;
        if (is_non_terminal(cch)) {
          is_all_teiminal = false;
          break;
        }
      }
      if (is_all_teiminal) {
        for (auto sc : c.get_r()) {
          for (auto ch : sc) {
            std::string cch = "";
            cch += ch;
            sderive.push(cch);
            is_derived[cch] = true;
          }
        }
      }
    }
  }

  // 符合条件一直推导
  while (!sderive.empty()) {
    auto cnt_derived = sderive.front();
    sderive.pop();
    
    for (auto c : getG()) {
      if (is_next[c]) {
        continue;
      }
      
      for (auto sc : c.get_r()) {
        bool is_all_derived = true;
        for (auto ch : sc) {
          std::string cch = "";
          cch += ch;
          if (!is_derived[cch] && !is_terminal(cch)) {
            is_all_derived = false;
          }
        }
        if (is_all_derived) {
          sderive.push(c.get_l());
          is_derived[c.get_l()] = true;
          value.push_back(c);
          is_next[c] = true;
        }
      }
    }
  }

  std::vector<grammar> nG;
  nG.clear();

  std::sort(value.begin(), value.end());

  std::map<grammar, bool> is_maped;

  // 将判别条件2处理后的语法存入after_second_check.out
  // 并将语法结构数组更新
  for (auto c : value) {
    if (is_maped[c]) {
      continue;
    }
    is_maped[c] = true;
    nG.push_back(c);
  }

  WG ng;
  ng.set_start(get_start());
  for (auto c : nG) {
    ng.add_grammar(c);
  }

  ng.cal_non_terminal();
  ng.cal_terminal();

  *this = ng;
  return (int) getG().size() == sz;
};

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
  std::cout << "Grammar Starts : " << this->start << "\n";
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