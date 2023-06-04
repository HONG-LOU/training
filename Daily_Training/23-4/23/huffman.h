#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "BitStream.h"
class Huffman
{
public:
  Huffman();
  ~Huffman();
  void compress(std::istream &is, std::ostream &os);
  void decompress(std::istream &is, std::ostream &os);

private:
  struct Node
  {
    uint8_t symbol_;
    uint32_t frequency_;
    Node *left_;
    Node *right_;
    Node(uint8_t symbol, uint32_t frequency);
    Node(uint32_t frequency, Node *left, Node *right);
    ~Node();
  };
  struct NodeCompare
  {
    bool operator()(const Node *node1, const Node *node2) const;
  };
  Node *buildTree(std::unordered_map<uint8_t, uint32_t> &frequencyTable);
  void buildCodeTable(Node *node, std::vector<bool> &code, std::unordered_map<uint8_t, std::vector<bool>> &codeTable);
  void deleteTree(Node *node);
};
#endif // HUFFMAN_H