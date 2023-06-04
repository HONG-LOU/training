#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "file.h"
#include "tree.h"
void printMenu();
void init();
void encode();
void compress();
void decode();
void printCode();
void printTree();
// 全局变量，保存哈夫曼树的根节点
Node *root = NULL;
int main()
{
  char choice;
  do
  {
    printMenu();
    scanf(" %c", &choice);
    switch (choice)
    {
    case 'I':
      init();
      break;
    case 'E':
      encode();
      break;
    case 'C':
      compress();
      break;
    case 'D':
      decode();
      break;
    case 'P':
      printCode();
      break;
    case 'T':
      printTree(root, 0);
      break;
    case 'Q':
      printf("Goodbye!\n");
      break;
    default:
      printf("Invalid choice, please try again.\n");
      break;
    }
  } while (choice != 'Q');
  // 释放哈夫曼树占用的内存
  freeTree(root);
  return 0;
}
// 打印菜单界面
void printMenu()
{
  printf("-----------------\n");
  printf("Huffman Encoding System\n");
  printf("-----------------\n");
  printf("I: Initialization\n");
  printf("E: Encoding\n");
  printf("C: Compression\n");
  printf("D: Decoding\n");
  printf("P: Print Code File\n");
  printf("T: Print Huffman Tree\n");
  printf("Q: Quit\n");
  printf("-----------------\n");
  printf("Please enter your choice: ");
}
// 初始化哈夫曼树
void init()
{
  char *filename = "Sourcefile.txt";
  root = buildHuffmanTree(filename);
  printf("Initialization completed.\n");
}
// 进行编码，并将编码结果保存到文件中
void encode()
{
  if (root == NULL)
  {
    printf("Huffman tree has not been initialized yet, please initialize first.\n");
    return;
  }
  char *inputFilename = "Sourcefile.txt";
  char *outputFilename = "HuffCode.txt";
  encodeFile(inputFilename, outputFilename, root);
  printf("Encoding completed.\n");
}
// 进行压缩，并将压缩结果保存到文件中
void compress()
{
  if (root == NULL)
  {
    printf("Huffman tree has not been initialized yet, please initialize first.\n");
    return;
  }
  char *inputFilename = "Sourcefile.txt";
  char *codeFilename = "HuffCode.txt";
  char *outputFilename = "CodeFile.txt";
  compressFile(inputFilename, codeFilename, outputFilename);
  printf("Compression completed.\n");
}
// 进行译码，并将译码结果保存到文件中
void decode()
{
  if (root == NULL)
  {
    printf("Huffman tree has not been initialized yet, please initialize first.\n");
    return;
  }
  char *inputFilename = "CodeFile.txt";
  char *outputFilename = "TextFile.txt";
  decodeFile(inputFilename, outputFilename, root);
  printf("Decoding completed.\n");
}
// 打印压缩后的代码文件
void printCode()
{
  char *filename = "CodeFile.txt";
  printCodeFile(filename);
  printf("\n");
}