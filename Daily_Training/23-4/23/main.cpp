#include <iostream>
#include "huffman.h"
using namespace std;
int main()
{
  string s = "hello world";
  Huffman huff;
  huff.build(s);
  string code = huff.encode(s);
  string decode = huff.decode(code);
  cout << "原始字符串：" << s << endl;
  cout << "编码后的字符串：" << code << endl;
  cout << "解码后的字符串：" << decode << endl;
  return 0;
}