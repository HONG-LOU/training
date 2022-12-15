/**
 *    author:  HONG-LOU
 *    created: 2022-12-15 13:28:57
**/
#include <bits/stdc++.h>

using namespace std;

bool FileStringReplace(ifstream &instream, ofstream &outstream, std::string a, std::string b)
{
  string str;
  size_t pos = 0;
  int sz = (int) a.size();
  while (getline(instream, str))
  {
    pos = str.find(a);
    int pos2 = str.find("dOUble");
    if (pos2 != string::npos) {
      str = str.replace(pos2, 6, "float");
    }
    int pos3 = str.find("Double");
    if (pos3 != string::npos) {
      str = str.replace(pos3, 6, "float");
    }
    int pos4 = str.find("douBLE");
    if (pos4 != string::npos) {
      str = str.replace(pos4, 6, "float");
    }
    int pos5 = str.find("iN");
    if (pos5 != string::npos) {
      str = str.replace(pos5, 2, "out");
    }
    int pos6 = str.find("IN");
    if (pos6 != string::npos) {
      str = str.replace(pos6, 2, "out");
    }
    int pos7 = str.find("In");
    if (pos7 != string::npos) {
      str = str.replace(pos7, 2, "out");
    }
    int pos8 = str.find("(outn");
    if (pos8 != string::npos) {
      str = str.replace(pos8, 5, "(\"out");
    }
    if (pos != string::npos)
    {
      str = str.replace(pos, sz, b);
      outstream << str << endl;
      continue;
    }
    outstream << str << endl;
  }
  return true;
}


auto main() -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
  
  std::string a, b;
  std::cin >> a >> b;
  
  string file_path = "filein.txt";
  string out_path = "fileout.txt";
  ifstream instream(file_path);
  ofstream outstream(out_path);
  FileStringReplace(instream, outstream, a, b);
  instream.close();
  outstream.close();

  return 0;
}