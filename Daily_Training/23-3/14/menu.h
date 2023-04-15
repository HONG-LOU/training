/**
 *    author:  HONG-LOU
 *    created: 2023-03-14 13:37:11
**/
#include <bits/stdc++.h>
#include "message.h"

auto menu () -> int {
  std::vector<std::string> s(6);
  s[0] = "Student Elective Course Management System";
  s[1] = "1. Enter course information";
  s[2] = "2. Course information deletion";
  s[3] = "3. Course Information view";
  s[4] = "4. Course Search";
  s[5] = "5. Exit procedure";
  showmenu(s);

  std::string input;
  std::cin >> input;
  std::cout << std::endl;
  if (input == "1") {
    return 1;
  }
  else if (input == "2") {
    return 2;
  }
  else if (input == "3") {
    return 3;
  }
  else if (input == "4") {
    return 4;
  }
  else if (input == "5") {
    return 5;
  }
  else {
    return -1;
  }
}