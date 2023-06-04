#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
// 建立哈夫曼树的节点
Node *createNode(char symbol, int freq)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->symbol = symbol;
  node->freq = freq;
  node->left = NULL;
  node->right = NULL;
  return node;
}
// 释放哈夫曼树占用的内存
void freeNode(Node *node)
{
  if (node != NULL)
  {
    freeNode(node->left);
    freeNode(node->right);
    free(node);
  }
}
// 建立哈夫曼树
Node *buildHuffmanTree(char *filename)
{
  int freq[256] = {0}; // 统计每个字符出现的频率
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error: cannot open file %s\n", filename);
    return NULL;
  }
  char ch;
  while ((ch = fgetc(fp)) != EOF)
  {
    freq[ch]++;
  }
  fclose(fp);
  // 将所有出现过的字符作为叶子节点，构建哈夫曼树
  PriorityQueue *pq = createPriorityQueue();
  for (int i = 0; i < 256; i++)
  {
    if (freq[i] > 0)
    {
      Node *node = createNode(i, freq[i]);
      enqueue(pq, node);
    }
  }
  while (pq->size > 1)
  {
    Node *node1 = dequeue(pq);
    Node *node2 = dequeue(pq);
    int freqSum = node1->freq + node2->freq;
    Node *newNode = createNode('\0', freqSum);
    newNode->left = node1;
    newNode->right = node2;
    enqueue(pq, newNode);
  }
  Node *root = dequeue(pq);
  freePriorityQueue(pq);
  return root;
}
// 递归地打印哈夫曼树
void printTree(Node *node, int level)
{
  if (node == NULL)
  {
    return;
  }
  printTree(node->right, level + 1);
  printf("\n");
  if (node->symbol == '\n')
  {
    printf("\\n");
  }
  else
  {
    printf("%c", node->symbol);
  }
  for (int i = 0; i < level; i++)
  {
    printf("    ");
  }
  printf("(%d)", node->freq);
  printTree(node->left, level + 1);
}
// 生成哈夫曼编码表
void generateCodeTable(Node *node, char *code, int depth, CodeTable *table)
{
  if (node == NULL)
  {
    return;
  }
  if (node->left == NULL && node->right == NULL)
  {
    code[depth] = '\0';
    CodeTableEntry entry = {node->symbol, strdup(code)};
    addEntry(table, entry);
  }
  else
  {
    code[depth] = '0';
    generateCodeTable(node->left, code, depth + 1, table);
    code[depth] = '1';
    generateCodeTable(node->right, code, depth + 1, table);
  }
}
// 释放哈夫曼编码表占用的内存
void freeCodeTable(CodeTable *table)
{
  for (int i = 0; i < table->size; i++)
  {
    free(table->entries[i].code);
  }
  free(table->entries);
  free(table);
}
// 打印哈夫曼编码表
void printCodeTable(CodeTable *table)
{
  for (int i = 0; i < table->size; i++)
  {
    printf("%c: %s\n", table->entries[i].symbol, table->entries[i].code);
  }
}
// 在哈夫曼编码表中查找指定字符对应的编码
char *getCode(CodeTable *table, char symbol)
{
  for (int i = 0; i < table->size; i++)
  {
    if (table->entries[i].symbol == symbol)
    {
      return table->entries[i].code;
    }
  }
  return NULL;
}