#ifndef _HUFFMAN_H
#define _HUFFMAN_H
// 哈夫曼树节点
typedef struct _HuffmanNode
{
  unsigned char c;            // 字符
  int freq;                   // 频率
  struct _HuffmanNode *left;  // 左子节点
  struct _HuffmanNode *right; // 右子节点
} HuffmanNode;
// 优先队列节点
typedef struct _PriorityQueueNode
{
  HuffmanNode *node;               // 哈夫曼树节点
  struct _PriorityQueueNode *next; // 下一个节点
} PriorityQueueNode;
// 优先队列
typedef struct _PriorityQueue
{
  int size;                // 大小
  PriorityQueueNode *head; // 头节点
  PriorityQueueNode *tail; // 尾节点
} PriorityQueue;
// 创建节点
HuffmanNode *create_node(unsigned char c, int freq);
// 释放节点
void free_node(HuffmanNode *node);
// 创建哈夫曼树
HuffmanNode *create_tree(int *freq);
// 创建编码表
void create_encoding_table(HuffmanNode *node, char **table, char *code);
// 释放编码表
void free_encoding_table(char **table);
// 压缩文件
void compress_file(FILE *in_file, FILE *out_file, char **table);
// 解压文件
void decompress_file(FILE *in_file, FILE *out_file, HuffmanNode *root, int file_size);
// 哈夫曼编码
void encode(char *in_filename, char *out_filename);
// 哈夫曼解码
void decode(char *in_filename, char *out_filename);
// 创建优先队列
PriorityQueue *create_priority_queue();
// 销毁优先队列
void destroy_priority_queue(PriorityQueue *queue);
// 入队
void enqueue(PriorityQueue *queue, HuffmanNode *node);
// 出队
HuffmanNode *dequeue(PriorityQueue *queue);
#endif