#ifndef HUFFMAN_H
#define HUFFMAN_H
// 定义哈夫曼树的节点
typedef struct node
{
    char symbol;        // 节点代表的字符
    int freq;           // 字符出现的频率
    struct node *left;  // 左子树
    struct node *right; // 右子树
} Node;
// 定义哈夫曼编码表的条目
typedef struct codeTableEntry
{
    char symbol; // 字符
    char *code;  // 编码
} CodeTableEntry;
// 定义哈夫曼编码表
typedef struct codeTable
{
    CodeTableEntry *entries; // 条目数组
    int size;                // 条目数量
    int capacity;            // 条目数组的容量
} CodeTable;
// 建立哈夫曼树的节点
Node *createNode(char symbol, int freq);
// 释放哈夫曼树占用的内存
void freeNode(Node *node);
// 建立哈夫曼树
Node *buildHuffmanTree(char *filename);
// 递归地打印哈夫曼树
void printTree(Node *node, int level);
// 生成哈夫曼编码表
void generateCodeTable(Node *node, char *code, int depth, CodeTable *table);
// 释放哈夫曼编码表占用的内存
void freeCodeTable(CodeTable *table);
// 打印哈夫曼编码表
void printCodeTable(CodeTable *table);
// 在哈夫曼编码表中查找指定字符对应的编码
char *getCode(CodeTable *table, char symbol);
#endif