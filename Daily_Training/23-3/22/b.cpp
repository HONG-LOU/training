/**
 *    author:  HONG-LOU
 *    created: 2023-04-02 12:26:20
**/
#include <bits/stdc++.h>
using namespace std;

string gjd(string s1, string s2)
{
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  for(int i = 0; i < abs((int)s1.size() - (int)s2.size() + 1); i ++) s1 += "0", s2 += "0";
  for(int i = 0; i < min(s1.size(), s2.size()); i ++) {
    int a = s1[i] - '0', b = s2[i] - '0';
    int sm = a + b;
    if(sm >= 10) {
      sm -= 10;
      s1[i] = sm + '0';
      s1[i + 1] = ((s1[i + 1] - '0' + 1) + '0');
    } else {
      s1[i] = sm + '0';
    }
  }
  reverse(s1.begin(), s1.end());
  return s1;
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  std::string a, b, c;
  std::reverse(s.begin(), s.end());
  for (int i = 0; i < (int) s.size() - 1; i += 2) {
    std::string cnt = "";
    cnt += s[i];
    cnt += s[i + 1];
    if (cnt == "00") {
      a += '0';
    }
    else if (cnt == "10") {
      a += "1";
    }
    else if (cnt == "01") {
      a += '2';
    }
    else {
      a += '3';
    }
  }
  if ((int) s.size() & 1) {
    a += '1';
  }
  for (int i = 0; i < (int) s.size(); i += 3) {
    if (i + 1 >= (int) s.size()) {
      b += '1';
      break;
    }
    if (i + 2 >= (int) s.size()) {
      if(s[i]=='0') b += '2';
      else b += '3';
      break;
    }
    if (s[i] == '0') {
      if (s[i + 1] == '0') {
        if(s[i+2] == '0'){
          b += '0';
        }
        else b += '4';
      }
      else {
        if(s[i+2]=='0') b += '2';
        else b += '6';
      }
    }
    else {
      if (s[i + 1] == '0') {
        if(s[i+2]=='0') b += '1';
        else b += '5';
      }
      else {
        if(s[i+2]=='0') b += '3';
        else b += '7';
      }
    }
    // std::cout << a << std::endl;
  }
  // reverse(s.begin(), s.end());
  string sum = "0", p2 = "1";
  for(int i = 0; i < s.size(); i ++) {
    if(s[i] == '1') {
      sum = gjd(sum, p2);
    }
    p2 = gjd(p2, p2);
    // cout << p2 << endl;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  bool ok = 0;
  // cout << sum << endl;
  for(int i = 0 ; i< sum.size(); i ++) {
    if(sum[i] != '0') ok = 1;
    if(ok) cout << sum[i];
  }
  return 0;
}