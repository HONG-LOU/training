/**
 *    author:  宁智伟
 *    created: 2024-04-07 17:45:52
**/
#include <bits/stdc++.h>

std::ifstream in;
std::ofstream out;
std::ofstream first_check_os;
std::ifstream read_after_first_check;
std::ofstream second_check_os;
std::ifstream read_after_second_check;

// 语法结构体存储语法，包含两部分，左部字符和右部字符集合
struct g {
  char left;
  std::vector<std::string> right;
  int operator < (const g &aa) const {
		if(aa.left == left) {
			return right.size() < aa.right.size();
		}
		return left < aa.left;
	}
};

std::vector<g> G;

std::set<char> t; // 存储初始终结符，set去重
std::set<char> n; // 存储初始非终结符，set去重

 // 结构体数组存储语法集合

std::vector<char> terminal; // 终结符集合，vector方便处理和查看
std::vector<char> non_terminal; // 非终结符集合

std::vector<char> checked_N; // 存储判别条件1后的合法非终结符

// 初始函数，输入，分析，存储终结符和非终结符
auto cinit (std::ifstream &iin) -> void {
  n.clear();
  t.clear();

  terminal.clear();
  non_terminal.clear();
  std::string s;

  // 文件流输入文法内容
  while (iin >> s) {
    char c = s[0];
    std::vector<std::string> be_push;
    be_push.clear();
    n.insert(s[0]);
    int len = (int) s.size();
    std::string cnt = "";
    for (int i = 1; i < len; i++) {
      if (s[i] == ':' || s[i] == '=') {
        continue;
      }
      if (s[i] == '|') {
        be_push.push_back(cnt);
        cnt = "";
      }
      else {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          n.insert(s[i]);
        }
        else {
          t.insert(s[i]);
        }
        cnt += s[i];
      }
    }
    if (!cnt.empty()) {
      be_push.push_back(cnt);
    }
    G.push_back({c, be_push});
  }

  // 更新终结符和非终结符容器
  terminal = std::vector<char>(t.begin(), t.end());
  non_terminal = std::vector<char>(n.begin(), n.end());
};



// 判断是否属于终结符集合
auto is_terminal (char c) -> bool {
  for (auto cnt : terminal) {
    if (c == cnt) {
      return true;
    }
  }
  return false;
};

// 判断是否属于非终结符集合
auto is_non_terminal (char c) -> bool {
  for (auto cnt : non_terminal) {
    if (c == cnt) {
      return true;
    }
  }
  return false;
};

// 判别条件1
auto first_check () -> bool {
  int sz = (int) G.size();
  std::map<char, bool> dervied;

  dervied.clear();

  dervied['Z'] = true;

  std::queue<char> derive;
  derive.push('Z');

  while (!derive.empty()) {
    auto new_be_derived = derive.front();
    checked_N.push_back(new_be_derived);
    derive.pop();
    for (auto s : G) {
      if (s.left == new_be_derived) {
        for (auto r : s.right) {
          for (auto ch : r) {
            if (!dervied[ch] && is_non_terminal(ch)) {
              derive.push(ch);
              dervied[ch] = true;
            }
          }
          
        }
      }
    }
  }

  std::vector<g> nG;

  for (auto c : G) {
    if (dervied[c.left]) {
      nG.push_back(c);
    }
  }

  G = nG;

  n.clear();
  for (auto c : G) {
    n.insert(c.left);
    for (auto sc : c.right) {
      for (auto ch : sc) {
        if (ch >= 'A' && ch <= 'Z') {
          n.insert(ch);
        }
      }
      
    }
  }

  non_terminal = std::vector<char>(n.begin(), n.end());

  for (auto c : G) {
    first_check_os << c.left << "::=";
    for (auto nc : c.right) {
      first_check_os << nc << ' ';
    }
    first_check_os << "\n";
  }
  return (int) G.size() == sz;
};

// 判别条件2
auto second_check () -> bool {
  int sz = (int) G.size();
  std::map<struct g, bool> is_next; // 用来判断这句语法是否已经推导过
  is_next.clear();

  std::vector<struct g> value; // 存储可以推导到的语法

  std::map<char, bool> is_derived; // 判断当前符号是否可以推导到

  std::queue<char> sderive; // 队列存储当前推导的符号

  // 遍历所有语法找到右部只包含终结符的语法
  for (auto c : G) {
    for (auto sc : c.right) {
      bool is_all_teiminal = true;
      for (auto ch : sc) {
        if (is_non_terminal(ch)) {
          is_all_teiminal = false;
          break;
        }
      }
      if (is_all_teiminal) {
        for (auto sc : c.right) {
          for (auto ch : sc) {
            sderive.push(ch);
            is_derived[ch] = true;
          }
        }
      }
    }
  }

  auto sq = sderive;
  while (!sq.empty()) {
    std::cout << sq.front() << ' ';
    sq.pop();
  }
  std::cout << "\n";

  // 符合条件一直推导
  while (!sderive.empty()) {
    auto cnt_derived = sderive.front();
    sderive.pop();
    for (auto c : G) {
      if (is_next[c]) {
        continue;
      }
      
      for (auto sc : c.right) {
        bool is_all_derived = true;
        for (auto ch : sc) {
          if (!is_derived[ch] && !is_terminal(ch)) {
            is_all_derived = false;
          }
        }
        if (is_all_derived) {
          sderive.push(c.left);
          is_derived[c.left] = true;
          value.push_back(c);
          is_next[c] = true;
        }
      }
    }
  }

  std::vector<g> nG;
  nG.clear();

  std::sort(value.begin(), value.end());

  std::map<struct g, bool> is_maped;

  // 将判别条件2处理后的语法存入after_second_check.out
  // 并将语法结构数组更新
  for (auto c : value) {
    if (is_maped[c]) {
      continue;
    }
    is_maped[c] = true;
    second_check_os << c.left << "::=";
    for (auto sc : c.right) {
      second_check_os << sc << ' ';
    }
    second_check_os << "\n";

    nG.push_back(c);
  }

  G = nG;
  return (int) G.size() == sz;
};

// 更新集合，每次判别后集合元素发生变化
auto update_set () -> void {
  n.clear();
  t.clear();
  // terminal.clear();
  // non_terminal.clear();

  for (auto c : G) {
    n.insert(c.left);
    for (auto sc : c.right) {
      for (auto ch : sc) {
        if (!is_non_terminal(ch)) {
          t.insert(ch);
        }
      }
    }
  }

  terminal = std::vector<char>(t.begin(), t.end());
  non_terminal = std::vector<char>(n.begin(), n.end());
};

// 打印函数，输出文法集合以及终结符以及和非终结符集合
auto print () -> void {
  out << " {\n";
  for (auto c : G) {
    out << "  " << c.left << " ==> ";
    int sz = (int) c.right.size() - 1;
    for (auto nc : c.right) {
      out << nc;
      if (sz > 0) {
        out << '|';
        sz--;
      }
    }
    out << "\n";
  }
  out << "\n  Terminal : ";
  for (auto cnt : terminal) {
    out << cnt << ' ';
  }
  out << "\n  Non-Terminal : ";
  for (auto cnt : non_terminal) {
    out << cnt << ' ';
  }
  out << "\n};\n\n";
};

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  // 使用文件流打开要处理的文件
  std::string f;

  std::cout << "Please Input Grammar File Name : ";
  std::cin >> f;
  
  in.open(f);
  out.open("result.out");
  first_check_os.open("after_first_check.out");
  read_after_first_check.open("after_first_check.out");
  second_check_os.open("after_second_check.out");
  read_after_second_check.open("after_second_check.out");

  // while (true) {
  //   std::cout << "1.Initial\n2.Print\n3.First Check\n4.Second Check\n5.Exit\n\n\n";

  //   int choi;
  //   std::cin >> choi;

  //   if (choi == 1) {
  //     cinit(in);
  //   }
  //   else if (choi == 2) {
  //     print();
  //     std::cout << "The results are stored in a file\n\n";
  //   }
  //   else if (choi == 3) {
  //     first_check();
  //   }
  //   else if (choi == 4) {
  //     second_check();
  //   }
  //   else {
  //     break;
  //   }
  // }

  cinit(in); // 初始化

  out << "Initial Grammar Set :";

  print();

  bool ok1 = false, ok2 = false;

  while (!ok1 && !ok2) {
    if (!ok1) {
      ok1 = first_check(); // 判别条件1
      out << "After First Check :";
      print();
    }
    if (!ok2) {
      ok2 = second_check();
      update_set();
      out << "After Second Check :";
      print();
    }
  }

  // first_check(); // 判别条件1

  // out << "After First Check :";

  // print();

  // second_check();

  // update_set();

  // out << "After Second Check :";

  // print();


  in.close();
  out.close();
  first_check_os.close();
  second_check_os.close();
  read_after_first_check.close();
  read_after_second_check.close();

  return 0;
}