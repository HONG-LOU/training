/**
 *    author:  HONG-LOU
 *    created: 2024-04-13 19:23:30
**/
#include "grammar.h"
#include "show.h"

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

void WG::split_grammar() {
  WG ng;
  ng.set_start(this->get_start());

  for (auto c : this->getG()) {
    std::string cnt = c.get_l();
    cnt += "::=";
    for (auto cc : c.get_r()) {
      std::string ncnt = cnt + cc;
      ng.add_grammar(ncnt);
    }
  }

  ng.cal_non_terminal();
  ng.cal_terminal();
  shows("Grammar Splited.");
  *this = ng;
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

  shows("Non-terminators Finded.");
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
  shows("Terminators Finded.");
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
  shows("Type I Discrimination.");
  auto G = this->getG();
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

  auto fc = ng.getG();
  std::sort(fc.begin(), fc.end());

  ng.G = fc;

  ng.cal_non_terminal();
  ng.cal_terminal();

  *this = ng;
  return (int) getG().size() == sz;
}

// 判别条件2
bool WG::second_check() {
  shows("Type II Discrimination.");
  auto G = this->getG();
  int sz = G.size();

  std::queue<grammar> vis;

  std::map<std::string, bool> checked;

  std::vector<grammar> f;

  std::map<std::string, bool> is_ok;

  for (auto c : terminal) {
    is_ok[c] = true;
  }

  for (auto c : G) {
    auto r = c.get_r()[0];
    bool ok = true;
    for (auto ch : r) {
      std::string cch = "";
      cch += ch;
      if (!is_ok[cch]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      is_ok[c.get_l()] = true;
      checked[c.get_l() + c.get_r()[0]] = true;
      vis.push(c);
      f.push_back(c);
    }
  }

  while (!vis.empty()) {
    auto q = vis.front();
    vis.pop();
    for (auto c : G) {
      if (checked[c.get_l() + c.get_r()[0]]) {
        continue;
      }
      bool is_all_ok = true;
      for (auto ch : c.get_r()[0]) {
        std::string cch = "";
        cch += ch;
        if (!is_ok[cch]) {
          // std::cout << "!ok == > " << c.get_l() << ' ' << c.get_r()[0] << ' ' << ch << "\n\n";
          is_all_ok = false;
          break;
        }
      }
      if (is_all_ok) {
        is_ok[c.get_l()] = true;
        checked[c.get_l() + c.get_r()[0]] = true;
        vis.push(c);
        f.push_back(c);
      }
    }
  }

  WG ng;
  ng.set_start(get_start());

  for (auto c : f) {
    ng.add_grammar(c);
  }

  auto fc = ng.getG();
  std::sort(fc.begin(), fc.end());

  ng.G = fc;

  ng.cal_non_terminal();
  ng.cal_terminal();

  *this = ng;
  return sz == (int) this->getG().size();
};

void WG::cycle_check() {
  bool fcheck = false, scheck = false;
  do {
    fcheck = first_check();
    print_grammar();
    scheck = second_check();
    print_grammar();
  } while (!fcheck && !scheck);
}

void WG::print_grammar() {
  std::cout << "Grammar([" << this->get_start() << "]) : {\n";
  for (auto c : this->G) {
    std::cout << "  " << c.get_l();
    std::cout << " ==> ";
    for (auto cc : c.get_r()) {
      std::cout << '[' << cc << ']' << ' ';
    }
    std::cout << "\n";
  }
  // this->cal_terminal();
  // this->cal_non_terminal();
  std::cout << "  Terminal : ";
  for (auto c : this->terminal) {
    std::cout << c << ' ';
  }
  std::cout << "\n";
  std::cout << "  Non-Terminal : ";
  for (auto c : this->non_terminal) {
    std::cout << c << ' ';
  }
  std::cout << "\n}\n\n";
}

bck::bck(/* args */)
{
}

bck::~bck()
{
}



bck WG::deduce(std::string s) {

  int cou = 0;

  bck nbck;
  std::deque<std::pair<std::string, std::string>> tr;
  std::map<std::string, bool> ys;
  std::map<std::string, bool> isvised;
  std::vector<std::deque<std::string>> fres;
  std::vector<std::deque<std::pair<std::string, std::string>>> sres;
  std::map<char, std::vector<std::string>> mp;
  std::deque<std::string> ans;
  for (auto c : this->getG()) {
    for (auto cc : c.get_r()) {
      mp[c.get_l()[0]].push_back(cc);
    }
  }

  ans.push_back(this->get_start());

  std::function<void(std::string)> dfs = [&] (std::string cnt) {
    // if (cou++ > 10) {
    //   return;
    // }
    if (cnt.length() > s.length()) {
      return;
    }
    if (cnt == s) {
      std::string res = "";
      for (auto st : ans) {
        res += st;
        if (st != ans.back()) {
          res += "==>";
        }
        else {
          res += "\n";
        }
      }
      if (!ys[res]) {
        fres.push_back(ans);
        sres.push_back(tr);
        ys[res] = true;
      }
      return;
    }
    for (int i = 0; i < cnt.length(); i++) {
      std::string sc = "";
      sc += cnt[i];
      if (is_non_terminal(sc)) {
        std::string nc;
        nc.clear();
        for (int j = 0; j < i; j++) {
          nc += cnt[j];
        }
        // std::cout << nc << "(" << nc.length() << ")" << ' ';
        for (auto p : mp[cnt[i]]) {
          std::string pp = "";
          pp += p;
          tr.push_back({sc, pp});
          nc += p;
          for (int j = i + 1; j < cnt.length(); j++) {
            nc += cnt[j];
          }
          // std::cout << "[" << nc << "]" << "\n";
          ans.push_back(nc);
          if (!isvised[nc]) {
            isvised[nc] = true;
            dfs(nc);
            isvised[nc] = false;
          }

          ans.pop_back();
          tr.pop_back();
          nc = "";
          for (int j = 0; j < i; j++) {
            nc += cnt[j];
          }
        }
        
      }
    }
  };
  dfs(this->get_start());
  if (fres.empty()) {
    bck fb;
    return fb;
  }
  nbck.set_f(fres[0]);
  nbck.set_s(sres[0]);
  return nbck;
}

void WG::print_sytax_tree(std::deque<std::string> q) {
  int mx = 0;
  for (auto c : q) {
    mx = std::max(mx, (int) c.length());
  }

}

/*
cnt is E
cnt is T
cnt is F
cnt is i
cnt is i(E)
cnt is i(T)
cnt is i(F)
cnt is i(i)
cnt is i(i)(E))
cnt is i(F)T*F)
cnt is i(T)E+T)
cnt is FT*F
cnt is iT*F
cnt is iF*F
cnt is ii*F
cnt is ii*i
cnt is ii*i(E)
cnt is ii*F(E)*F
cnt is iF*i
cnt is ii*i
cnt is ii*i(E)*i
cnt is iF*i(E)
cnt is iF*FT*F*F
cnt is iT*i
cnt is iF*i
cnt is iF*iT*F*i
cnt is iT*i(E)
cnt is iT*F(E)T*F
cnt is FF*F
cnt is iF*F
cnt is iF*F(E)F*F
cnt is Fi*F
cnt is ii*F
cnt is ii*F(E)i*F
cnt is Fi*i
cnt is ii*i
cnt is ii*i(E)i*i
cnt is Fi*i(E)
cnt is Fi*F(E)*F
cnt is FF*i
cnt is iF*i
cnt is iF*i(E)F*i
cnt is Fi*i
cnt is Fi*i(E)*i
cnt is FF*i(E)
cnt is FF*FT*F*F
cnt is FT*i
cnt is iT*i
cnt is iT*i(E)T*i
cnt is FF*i
cnt is FF*iT*F*i
cnt is FT*i(E)
cnt is TE+T
cnt is FE+T
cnt is iE+T
cnt is iT+T
cnt is iF+T
cnt is ii+T
cnt is ii+F
cnt is ii+i
cnt is ii+i(E)
cnt is ii+FT*F
cnt is ii+T(E)+T
cnt is iF+F
cnt is ii+F
cnt is ii+F(E)+F
cnt is iF+i
cnt is ii+i
cnt is ii+i(E)+i
cnt is iF+i(E)
cnt is iF+FT*F
cnt is iF+TT*F+T
cnt is iT+F
cnt is iF+F
cnt is iF+FT*F+F
cnt is iT+i
cnt is iF+i
cnt is iF+iT*F+i
cnt is iT+i(E)
cnt is iT+FT*F
cnt is iT+TE+T+T
cnt is iE+F
cnt is iT+F
cnt is iT+FE+T+F
cnt is iE+i
cnt is iT+i
cnt is iT+iE+T+i
cnt is iE+i(E)
cnt is iE+FT*F
cnt is iE+T(E)E+T
cnt is FT+T
cnt is iT+T
cnt is iT+T(E)T+T
cnt is FF+T
cnt is iF+T
cnt is iF+T(E)F+T
cnt is Fi+T
cnt is ii+T
cnt is ii+T(E)i+T
cnt is Fi+F
cnt is ii+F
cnt is ii+F(E)i+F
cnt is Fi+i
cnt is ii+i
cnt is ii+i(E)i+i
cnt is Fi+i(E)
cnt is Fi+FT*F
cnt is Fi+T(E)+T
cnt is FF+F
cnt is iF+F
cnt is iF+F(E)F+F
cnt is Fi+F
cnt is Fi+F(E)+F
cnt is FF+i
cnt is iF+i
cnt is iF+i(E)F+i
cnt is Fi+i
cnt is Fi+i(E)+i
cnt is FF+i(E)
cnt is FF+FT*F
cnt is FF+TT*F+T
cnt is FT+F
cnt is iT+F
cnt is iT+F(E)T+F
cnt is FF+F
cnt is FF+FT*F+F
cnt is FT+i
cnt is iT+i
cnt is iT+i(E)T+i
cnt is FF+i
cnt is FF+iT*F+i
cnt is FT+i(E)
cnt is FT+FT*F
cnt is FT+TE+T+T
cnt is FE+F
cnt is iE+F
cnt is iE+F(E)E+F
cnt is FT+F
cnt is FT+FE+T+F
cnt is FE+i
cnt is iE+i
cnt is iE+i(E)E+i
cnt is FT+i
cnt is FT+iE+T+i
cnt is FE+i(E)
cnt is FE+FT*F
cnt is FE+TT*FE+T
cnt is TT+T
cnt is FT+T
cnt is FT+TT*FT+T
cnt is TF+T
cnt is FF+T
cnt is FF+TT*FF+T
cnt is Ti+T
cnt is Fi+T
cnt is Fi+TT*Fi+T
cnt is Ti+F
cnt is Fi+F
cnt is Fi+FT*Fi+F
cnt is Ti+i
cnt is Fi+i
cnt is Fi+iT*Fi+i
cnt is Ti+i(E)
cnt is Ti+FT*F
cnt is Ti+T(E)+T
cnt is TF+F
cnt is FF+F
cnt is FF+FT*FF+F
cnt is Ti+F
cnt is Ti+F(E)+F
cnt is TF+i
cnt is FF+i
cnt is FF+iT*FF+i
cnt is Ti+i
cnt is Ti+i(E)+i
cnt is TF+i(E)
cnt is TF+FT*F
cnt is TF+TT*F+T
cnt is TT+F
cnt is FT+F
cnt is FT+FT*FT+F
cnt is TF+F
cnt is TF+FT*F+F
cnt is TT+i
cnt is FT+i
cnt is FT+iT*FT+i
cnt is TF+i
cnt is TF+iT*F+i
cnt is TT+i(E)
cnt is TT+FT*F
cnt is TT+TE+T+T
cnt is TE+F
cnt is FE+F
cnt is FE+FT*FE+F
cnt is TT+F
cnt is TT+FE+T+F
cnt is TE+i
cnt is FE+i
cnt is FE+iT*FE+i
cnt is TT+i
cnt is TT+iE+T+i
cnt is TE+i(E)
cnt is TE+FT*F
*/