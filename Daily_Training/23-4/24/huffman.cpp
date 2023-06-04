#include <iostream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;
// 哈夫曼树节点
struct Node
{
  char ch;
  int freq;
  Node *left;
  Node *right;
  Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};
// 优先队列比较函数
struct Compare
{
  bool operator()(Node *a, Node *b)
  {
    return (a->freq > b->freq);
  }
};
// 统计字符频度
void countFrequency(string filename, int freq[])
{
  ifstream in(filename);
  if (!in)
  {
    cout << "Fail to open file!" << endl;
    return;
  }
  char c;
  while (in.get(c))
  {
    freq[c]++;
  }
  in.close();
}
// 建立哈夫曼树
Node *buildHuffmanTree(int freq[])
{
  priority_queue<Node *, vector<Node *>, Compare> pq;
  for (int i = 0; i < 256; i++)
  {
    if (freq[i] > 0)
    {
      pq.push(new Node(i, freq[i]));
    }
  }
  while (pq.size() > 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();
    Node *parent = new Node(-1, left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    pq.push(parent);
  }
  return pq.top();
}
// 编码
void encode(Node *root, string code[], string currCode)
{
  if (!root)
  {
    return;
  }
  if (root->ch != -1)
  {
    code[root->ch] = currCode;
  }
  encode(root->left, code, currCode + "0");
  encode(root->right, code, currCode + "1");
}
// 压缩
void compressFile(string srcFile, string destFile, string code[])
{
  ifstream in(srcFile);
  if (!in)
  {
    cout << "Fail to open file!" << endl;
    return;
  }
  ofstream out(destFile);
  char c;
  string codeStr;
  while (in.get(c))
  {
    codeStr += code[c];
    while (codeStr.length() >= 8)
    {
      char byte = 0;
      for (int i = 0; i < 8; i++)
      {
        byte <<= 1;
        if (codeStr[i] == '1')
        {
          byte |= 1;
        }
      }
      out.put(byte);
      codeStr.erase(0, 8);
    }
  }
  if (codeStr.length() > 0)
  {
    char byte = 0;
    for (int i = 0; i < codeStr.length(); i++)
    {
      byte <<= 1;
      if (codeStr[i] == '1')
      {
        byte |= 1;
      }
    }
    byte <<= (8 - codeStr.length());
    out.put(byte);
  }
  in.close();
  out.close();
}
// 译码
void decodeFile(string srcFile, string destFile, Node *root)
{
  ifstream in(srcFile);
  if (!in)
  {
    cout << "Fail to open file!" << endl;
    return;
  }
  ofstream out(destFile);
  Node *curr = root;
  char c;
  while (in.get(c))
  {
    for (int i = 7; i >= 0; i--)
    {
      if ((c >> i) & 1)
      {
        curr = curr->right;
      }
      else
      {
        curr = curr->left;
      }
      if (curr->ch != -1)
      {
        out.put(curr->ch);
        curr = root;
      }
    }
  }
  in.close();
  out.close();
}
// 打印代码文件
void printCodeFile(string filename)
{
  ifstream in(filename);
  if (!in)
  {
    cout << "Fail to open file!" << endl;
    return;
  }
  char c;
  int count = 1;
  while (in.get(c))
  {
    cout << c;
    if (count % 50 == 0)
    {
      cout << endl;
    }
    count++;
  }
  in.close();
}
// 显示哈夫曼树
void printHuffmanTree(Node *root, int indent)
{
  if (!root)
  {
    return;
  }
  for (int i = 0; i < indent; i++)
  {
    cout << " ";
  }
  if (root->ch != -1)
  {
    cout << root->ch << " (" << root->freq << ")" << endl;
  }
  else
  {
    cout << "X (" << root->freq << ")" << endl;
  }
  printHuffmanTree(root->left, indent + 4);
  printHuffmanTree(root->right, indent + 4);
}
int main()
{
  int freq[256] = {0};
  countFrequency("Sourcefile.txt", freq);
  Node *root = buildHuffmanTree(freq);
  string code[256];
  encode(root, code, "");
  compressFile("Sourcefile.txt", "CodeFile.txt", code);
  decodeFile("CodeFile.txt", "TextFile.txt", root);
  printCodeFile("CodeFile.txt");
  printHuffmanTree(root, 0);
  return 0;
}