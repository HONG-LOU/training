/**
 *    author:  HONG-LOU
 *    created: 2022-10-28 13:27:26
**/
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>

#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

std::string get() {
  time_t nowtime;
  struct tm* p;;
  time(&nowtime);
  p = localtime(&nowtime);
  std::string s = "";
  s += std::to_string(1900 + p -> tm_year) + "-";
  s += ((int) std::to_string(p -> tm_mon + 1).size() < 2 ? "0" + std::to_string(p -> tm_mon + 1) : std::to_string(p -> tm_mon + 1)) + "-";
  s += ((int) std::to_string(p -> tm_mday).size() < 2 ? "0" + std::to_string(p -> tm_mday) : std::to_string(p -> tm_mday)) + " ";
  s += ((int) std::to_string(p -> tm_hour).size() < 2 ? "0" + std::to_string(p -> tm_hour) : std::to_string(p -> tm_hour)) + ":";
  s += ((int) std::to_string(p -> tm_min).size() < 2 ? "0" + std::to_string(p -> tm_min) : std::to_string(p -> tm_min)) + ":";
  s += ((int) std::to_string(p -> tm_sec).size() < 2 ? "0" + std::to_string(p -> tm_sec) : std::to_string(p -> tm_sec));
  return s;
}

int getss() {
  time_t nowtime;
  struct tm* p;;
  time(&nowtime);
  p = localtime(&nowtime);  
  return p -> tm_sec;
}
/*
|----|
|    |
|____|
|    |
|    |
|----|
*/

auto main() -> int {
  time_t nowtime;
  struct tm* p;;
  time(&nowtime);
  p = localtime(&nowtime);  
  
  int cnt = getss();

  while (true) {
    int sec = getss();
    cnt %= 60;
    if (cnt == 0) {
      Beep(800, 1500);
      Sleep(3000);
      cnt += 4;
      continue;
    }
    if (sec == ((cnt + 1) % 60)) {
      system("cls");
      std::cout << (get());
      cnt += 1;
      Beep(500, 300);
    }
    
  }
  return 0;
}