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
  std::string start;
  std::vector<std::string> terminal;
  std::vector<std::string> non_terminal;
public:
  WG();
  void add_grammar(grammar g);
  void split_grammar();
  std::vector<grammar> getG() {
    return this->G;
  }
  void set_start(std::string s) {
    this->start = s;
  }
  std::string get_start() {
    return this->start;
  }
  void print_grammar();
  // void set_this(WG g) {
  //   *this = g;
  // }
  void cal_terminal();
  void cal_non_terminal();
  bool is_terminal(std::string s);
  bool is_non_terminal(std::string s);
  bool first_check();
  bool second_check();
  void cycle_check();
  std::vector<std::deque<std::string>> deduce(std::string s);
  ~WG();
};
