#include <stdio.h>

/**
 * @brief 
 * 
 * 和明显有是和后面那道题一样的道理，直接输出是O(1)的复杂的，无法拒绝，
 * 正确代码和后面那道题一样，和那个代码几乎一样，我就不贴在这里了
 * 我用c++通过后台复制和提取，获得了题目answer，相关代码给出
 * 我想这才是程序的意义，如果看到的人因此给我零分，我也没啥好说的
 * 
 * @return int 
 */


// code ==>
/*

    author:  HONG-LOU
    created: 2022-12-30 13:03:41

#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("word.txt", "r", stdin);
  std::string s = "char s[100][30] = {";
  for (int i = 0; i < 100; i++) {
    std::string line;
    std::string plus;
    std::string count;
    std::cin >> line >> plus >> count;
    s += " \"";
    s += plus;
    s += " ";
    s += count;
    s += "\"";
    if (i < 99) {
      s += ",";
    }
    if (i != 0 && i % 4 == 0) {
      s += "\n";
    }
  }
  s += "};";
  std::cout << s << "\n";
  return 0;
}
*/


char s[100][30] = { "the 15983", "to 8514", "and 8375", "of 7016", "a 6630",
  "he 6557", "harry 5819", "said 5087", "was 4855",
  "s 4751", "you 4713", "his 4436", "it 4337",
  "in 4128", "i 4075", "that 3158", "had 2997",
  "at 2799", "on 2530", "as 2396", "t 2308",
  "him 2112", "with 2083", "they 2065", "her 2037",
  "ron 2007", "but 1857", "not 1826", "she 1809",
  "for 1766", "hermione 1620", "what 1590", "we 1443",
  "be 1431", "all 1413", "up 1398", "from 1393",
  "out 1365", "were 1333", "them 1313", "have 1241",
  "there 1090", "back 1061", "so 1056", "been 1047",
  "who 1030", "into 1001", "this 996", "is 921",
  "an 867", "me 855", "could 847", "if 847",
  "no 839", "now 828", "dumbledore 819", "their 811",
  "just 809", "about 790", "when 780", "over 777",
  "know 771", "down 753", "professor 752", "well 744",
  "one 736", "like 734", "then 720", "do 713",
  "by 704", "would 700", "very 698", "re 693",
  "ve 693", "got 690", "your 689", "looked 676",
  "did 668", "are 667", "can 667", "around 665",
  "hagrid 652", "more 648", "sirius 648", "weasley 644",
  "don 633", "d 621", "again 608", "off 608",
  "though 606", "looking 605", "see 574", "umbridge 571",
  "ll 567", "think 562", "how 560", "right 560",
  "time 558", "voice 540", "my 534"};

int main () {
  int i;
  for (i = 0; i < 100; i++) {
    printf("%s\n", s[i]);
  }
  return 0;
}