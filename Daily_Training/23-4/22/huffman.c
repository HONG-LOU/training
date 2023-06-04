#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 创建节点
HuffmanNode *create_node(unsigned char c, int freq)
{
  HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
  node->left = node->right = NULL;
  node->c = c;
  node->freq = freq;
  return node;
}
// 释放节点
void free_node(HuffmanNode *node)
{
  if (node != NULL)
  {
    free_node(node->left);
    free_node(node->right);
    free(node);
  }
}
// 创建哈夫曼树
HuffmanNode *create_tree(int *freq)
{
  PriorityQueue *queue = create_priority_queue();
  int i;
  for (i = 0; i < 256; i++)
  {
    if (freq[i] > 0)
    {
      enqueue(queue, create_node(i, freq[i]));
    }
  }
  while (queue->size > 1)
  {
    HuffmanNode *node1 = dequeue(queue);
    HuffmanNode *node2 = dequeue(queue);
    enqueue(queue, create_node(0, node1->freq + node2->freq));
    queue->tail->left = node1;
    queue->tail->right = node2;
  }
  HuffmanNode *root = dequeue(queue);
  free(queue);
  return root;
}
// 创建编码表
void create_encoding_table(HuffmanNode *node, char **table, char *code)
{
  if (node->left == NULL && node->right == NULL)
  {
    table[node->c] = (char *)malloc(strlen(code) + 1);
    strcpy(table[node->c], code);
  }
  else
  {
    char *left_code = (char *)malloc(strlen(code) + 2);
    char *right_code = (char *)malloc(strlen(code) + 2);
    sprintf(left_code, "%s0", code);
    sprintf(right_code, "%s1", code);
    create_encoding_table(node->left, table, left_code);
    create_encoding_table(node->right, table, right_code);
    free(left_code);
    free(right_code);
  }
}
// 释放编码表
void free_encoding_table(char **table)
{
  int i;
  for (i = 0; i < 256; i++)
  {
    if (table[i] != NULL)
    {
      free(table[i]);
    }
  }
}
// 压缩文件
void compress_file(FILE *in_file, FILE *out_file, char **table)
{
  unsigned char c;
  char *code;
  int bit_count = 0;
  unsigned char byte = 0;
  while (fread(&c, sizeof(unsigned char), 1, in_file) == 1)
  {
    code = table[c];
    while (*code != '\0')
    {
      if (*code == '1')
      {
        byte |= (1 << (7 - bit_count));
      }
      bit_count++;
      if (bit_count == 8)
      {
        fwrite(&byte, sizeof(unsigned char), 1, out_file);
        byte = 0;
        bit_count = 0;
      }
      code++;
    }
  }
  if (bit_count > 0)
  {
    fwrite(&byte, sizeof(unsigned char), 1, out_file);
  }
}
// 解压文件
void decompress_file(FILE *in_file, FILE *out_file, HuffmanNode *root, int file_size)
{
  HuffmanNode *node = root;
  unsigned char c;
  int bit_count = 0;
  while (fread(&c, sizeof(unsigned char), 1, in_file) == 1)
  {
    int i;
    for (i = 0; i < 8; i++)
    {
      if ((c & (1 << (7 - i))) != 0)
      {
        node = node->right;
      }
      else
      {
        node = node->left;
      }
      if (node->left == NULL && node->right == NULL)
      {
        fwrite(&node->c, sizeof(unsigned char), 1, out_file);
        node = root;
        file_size--;
        if (file_size == 0)
        {
          return;
        }
      }
    }
  }
}
// 哈夫曼编码
void encode(char *in_filename, char *out_filename)
{
  int freq[256] = {0};
  FILE *in_file = fopen(in_filename, "rb");
  FILE *out_file = fopen(out_filename, "wb");
  unsigned char c;
  while (fread(&c, sizeof(unsigned char), 1, in_file) == 1)
  {
    freq[c]++;
  }
  rewind(in_file);
  HuffmanNode *root = create_tree(freq);
  char *table[256] = {NULL};
  create_encoding_table(root, table, "");
  fwrite(freq, sizeof(int), 256, out_file);
  compress_file(in_file, out_file, table);
  free_node(root);
  free_encoding_table(table);
  fclose(in_file);
  fclose(out_file);
}
// 哈夫曼解码
void decode(char *in_filename, char *out_filename)
{
  int freq[256] = {0};
  FILE *in_file = fopen(in_filename, "rb");
  FILE *out_file = fopen(out_filename, "wb");
  fread(freq, sizeof(int), 256, in_file);
  HuffmanNode *root = create_tree(freq);
  int file_size = 0;
  int i;
  for (i = 0; i < 256; i++)
  {
    file_size += freq[i];
  }
  decompress_file(in_file, out_file, root, file_size);
  free_node(root);
  fclose(in_file);
  fclose(out_file);
}