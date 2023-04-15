/**
 *    author:  HONG-LOU
 *    created: 2023-03-16 14:19:15
**/
#include <bits/stdc++.h>
#include "menu.h"
#include "class.h"

std::vector<Course*> base;
int sum;

auto Init () -> void {
  std::ifstream myfile;
  myfile.open("input.txt");
  myfile >> sum;
  for (int i = 0; i < sum; i++) {
    std::string id;
    std::string name;
    std::string nature;
    double credit_hours;
    double lecture_hours;
    double lab_hours;
    double credits;
    std::string course_term;
    myfile >> id >> name >> nature >> credit_hours >> lecture_hours 
    >> lab_hours >> credits >> course_term;
    base.push_back(new Course(id, name, nature, credit_hours, lecture_hours, lab_hours, credits, course_term));
  }
  myfile.close();
}

auto add () -> void {
  showmes("please input Course information : ");
  std::string id;
  std::string name;
  std::string nature;
  double credit_hours;
  double lecture_hours;
  double lab_hours;
  double credits;
  std::string course_term;
  std::cin >> id >> name >> nature >> credit_hours >> lecture_hours 
  >> lab_hours >> credits >> course_term;
  std::cout << std::endl;
  for (auto cc : base) {
    if (cc->get_id() == id) {
      showmes("ID " + id + " exited!");
      return ;
    }
  }
  base.push_back(new Course(id, name, nature, credit_hours, lecture_hours, 
  lab_hours, credits, course_term));  
  sum = (int) base.size();
  std::ofstream myfile;
  myfile.open("input.txt");
  myfile << sum << std::endl;
  for (auto cnt : base) {
    myfile 
    << cnt->get_id() << ' ' 
    << cnt->get_name() << ' ' 
    << cnt->get_nature() << ' '
    << cnt->get_credit_hours() << ' ' 
    << cnt->get_lecture_hours() << ' '
    << cnt->get_lab_hours() << ' ' 
    << cnt->get_credits() << ' ' 
    << cnt->get_course_term() << std::endl;
  }
  myfile.close();
  showmes("Add Course Finished!");
}

auto del () -> void {
  showmes("Please input Course Id : ");
  std::string s;
  std::cin >> s;
  std::cout << std::endl;
  bool ok = false;
  std::vector<Course*> cnt;
  for (auto c : base) {
    if (c->get_id() == s) {
      ok = true;
      continue;
    }
    else {
      cnt.push_back(c);
    }
  }
  if (ok) {
    showmes("Course deleted!");
  }
  else {
    showmes("No such Course!");
  }
  base = cnt;
  std::ofstream myfile;
  myfile.open("input.txt");
  sum = (int) cnt.size();
  myfile << sum << std::endl;
  for (auto cntt : base) {
    myfile 
    << cntt->get_id() << ' ' 
    << cntt->get_name() << ' ' 
    << cntt->get_nature() << ' '
    << cntt->get_credit_hours() << ' ' 
    << cntt->get_lecture_hours() << ' '
    << cntt->get_lab_hours() << ' ' 
    << cntt->get_credits() << ' ' 
    << cntt->get_course_term() << std::endl;
  }
  myfile.close();
}

auto search () -> void {
  std::vector<std::string> ifo(2);
  ifo[0] = "1. Search by credits";
  ifo[1] = "2. Search by Course Nature";
  showmenu(ifo);
  int x;
  std::cin >> x;
  std::cout << std::endl;
  std::vector<std::string> ans;
  if (x == 1) {
    showmes("Please input credits : ");
    double c;
    std::cin >> c;
    std::cout << std::endl;
    for (auto cnt : base) {
      if (cnt->get_credits() == c) {
        ans.push_back(cnt->get_id() + " " + cnt->get_name());
      }
    }
    if ((int) ans.size() == 0) {
      showmes("Not found!");
    }
    else {
      showmenu(ans);
    }
  }
  else if (x == 2) {
    showmes("Please input nature : ");
    std::string c;
    std::cin >> c;
    std::cout << std::endl;
    for (auto cnt : base) {
      if (cnt->get_nature() == c) {
        ans.push_back(cnt->get_id() + " " + cnt->get_name());
      }
    }
    if ((int) ans.size() == 0) {
      showmes("Not found!");
    }
    else {
      showmenu(ans);
    }
  }
}

auto print () -> void {
  std::vector<std::string> cnt;
  for (auto s : base) {
    cnt.push_back(s->get_id() + " " + s->get_name());
  }
  showmenu(cnt);
}

auto ssort() {
  std::sort(base.begin(), base.end(), [&] (Course* a, Course* b) {
    return a->get_id() < b->get_id();
  });
  std::ofstream myfile;
  myfile.open("input.txt");
  sum = (int) base.size();
  myfile << sum << std::endl;
  for (auto cntt : base) {
    myfile 
    << cntt->get_id() << ' ' 
    << cntt->get_name() << ' ' 
    << cntt->get_nature() << ' '
    << cntt->get_credit_hours() << ' ' 
    << cntt->get_lecture_hours() << ' '
    << cntt->get_lab_hours() << ' ' 
    << cntt->get_credits() << ' ' 
    << cntt->get_course_term() << std::endl;
  }
  myfile.close();
}

auto main () -> int {
  // std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  Init();
  ssort();
  while (true) {
    int x = menu();
    system("cls");
    if (x == 1) {
      add();
      ssort();
    }
    else if (x == 2) {
      del();
    }
    else if (x == 3) {
      print();
    }
    else if (x == 4) {
      search();
    }
    else if (x == 5) {
      showmes("Bye-Bye!");
      return 0;
    }
    else {
      showmes("Error Input!");
    }
  }
  return 0;
}