#include <bits/stdc++.h>

class grammar
{
private:
  std::string l;
  std::vector<std::string> r;
public:
  grammar();
  grammar(std::string s);
  auto get_l() {
    return this->l;
  }
  auto get_r() {
    return this->r;
  }
  int operator < (const grammar &aa) const {
		if(aa.l == l) {
			return r.size() < aa.r.size();
		}
		return l < aa.l;
	}
  ~grammar();
};


class WG
{
private:
  std::vector<grammar> G;
  std::vector<std::string> terminal;
  std::vector<std::string> non_terminal;
public:
  WG();
  void add_grammar(grammar g);
  void print_grammar();
  void set_terminal(std::vector<std::string> t) {
    this->terminal = t;
  }
  void set_non_terminal(std::vector<std::string> n) {
    this->non_terminal = n;
  }
  void cal_terminal();
  void cal_non_terminal();
  ~WG();
};
