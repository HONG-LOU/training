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
  ifstream fin("original.txt");
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

void writeEncodedFile() {
  ofstream fout("encoded.txt");
  ifstream fin("original.txt");
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
  ifstream fin("encoded.txt");
  ofstream fout("decoded.txt");
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

int main() {
  readOriginalFile();
  buildHuffmanTree();
  encode(huffmanTree, "");
  writeEncodedFile();
  decodeFile();
  printTree(huffmanTree, 0);
  return 0;
}