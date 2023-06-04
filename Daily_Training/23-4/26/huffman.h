#include <bits/stdc++.h>

using namespace std;

struct Node {
  char ch;
  int freq;
  Node *left;
  Node *right;
};

class Compare {
public:
  bool operator()(Node *a, Node *b) {
    return a->freq > b->freq;
  }
};

map<char, int> freqMap;
map<char, string> codeMap;
Node *huffmanTree;

void readOriginalFile() {
  ifstream fin("SourceFile.txt");
  freqMap.clear();
  codeMap.clear();
  Node *node = new Node;
  node -> left = nullptr;
  node -> right = nullptr;
  huffmanTree = node;
  string line;
  while (getline(fin, line)) {
    for (char ch : line) {
      freqMap[ch]++;
    }
  }
  fin.close();
}

void buildHuffmanTree() {
  priority_queue<Node *, vector<Node *>, Compare> pq;
  for (auto it : freqMap) {
    Node *node = new Node;
    node->ch = it.first;
    node->freq = it.second;
    node->left = nullptr;
    node->right = nullptr;
    pq.push(node);
  }
  while (pq.size() > 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();
    Node *parent = new Node;
    parent->ch = '\0';
    parent->freq = left->freq + right->freq;
    parent->left = left;
    parent->right = right;
    pq.push(parent);
  }
  huffmanTree = pq.top();
}

void encode(Node *node, string code) {
  if (node == nullptr) {
    return;
  }
  if (node->left == nullptr && node->right == nullptr) {
    codeMap[node->ch] = code;
  }
  encode(node->left, code + '0');
  encode(node->right, code + '1');
}

void writeHuffCode() {
  ofstream fout("HuffCode.txt");
  for (auto it : codeMap) {
    fout << it.first << ' ' << it.second << std::endl;
  }
  fout.close();
}

void writeEncodedFile() {
  ofstream fout("CodeFile.txt");
  ifstream fin("SourceFile.txt");
  string line;
  while (getline(fin, line)) {
    for (char ch : line) {
      fout << codeMap[ch];
    }
  }
  fin.close();
  fout.close();
}

void decodeFile() {
  ifstream fin("CodeFile.txt");
  ofstream fout("TextFile.txt");
  Node *node = huffmanTree;
  char ch;
  while (fin.get(ch)) {
    if (ch == '0') {
      node = node->left;
    }
    else {
      node = node->right;
    }
    if (node->left == nullptr && node->right == nullptr) {
      fout << node->ch;
      node = huffmanTree;
    }
  }
  fin.close();
  fout.close();
}

void printCode() {
  ifstream fin("CodeFile.txt");
  int cnt = 0;
  char ch;
  while (fin.get(ch)) {
    std::cout << ch;
    cnt++;
    if (cnt % 50 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  fin.close();
}

void printTree(Node* node, int level) {
  if (node == nullptr) {
    return;
  }
  for (int i = 0; i < level; i++) {
    cout << "  ";
  }
  if (node->ch == '\0') {
    cout << node->freq << endl;
  } else {
    cout << node->ch << " (" << node->freq << ")" << endl;
  }
  printTree(node->left, level + 1);
  printTree(node->right, level + 1);
}

std::string menu() {
  std::cout << "========================" << std::endl;
  std::cout << "|   Huffman ED System  |" << std::endl;
  std::cout << "|======================|" << std::endl;
  std::cout << "|   I.Initialization   |" << std::endl;
  std::cout << "|      E.Encoding      |" << std::endl;
  std::cout << "|      C.Compress      |" << std::endl;
  std::cout << "|      D.Decoding      |" << std::endl;
  std::cout << "|        P.Print       |" << std::endl;
  std::cout << "|     T.Treeprinting   |" << std::endl;
  std::cout << "|        Q.Quit        |" << std::endl;
  std::cout << "========================" << std::endl << std::endl;
  std::string x;
  std::cin >> x;
  std::cout << std::endl;
  return x;
}

void test() {
  while (true) {
    std::string c = menu();
    if (c == "I") {
      readOriginalFile();
      buildHuffmanTree();
    }
    else if (c == "E") {
      encode(huffmanTree, "");
      writeHuffCode();
    }
    else if (c == "C") {
      writeEncodedFile();
    }
    else if (c == "D") {
      decodeFile();
    }
    else if (c == "P") {
      printCode();
    }
    else if (c == "T") {
      printTree(huffmanTree, 0);
    }
    else if (c == "Q") {
      std::cout << "Bye-Bye!" << std::endl;
      exit(0);
    }
    else {
      std::cout << "Error Input!" << std::endl;
      continue;
    }
    std::cout << "\nFinished!" << std::endl << std::endl;
  }
}