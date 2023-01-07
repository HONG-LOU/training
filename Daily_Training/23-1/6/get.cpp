/**
 *    author:  HONG-LOU
 *    created: 2023-01-06 14:49:43
**/
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("score.txt", "r", stdin);
  freopen("final.txt", "w", stdout);
  // 1	2021-2022-1	000000202	大学生心理健康	0			2	36	0		否	考试	正常考试	必修	公共课	
  for (int i = 0; i < 32; i++) {
    std::string s;
    std::string name;
    double score;
    double value;
    std::cin >> s >> s >> s >> name >> score >> value >> s >> s >> s >> s >> s >> s >> s;
    std::cout << name << ' ' << score << ' ' << value << "\n";
  }
  return 0;
}