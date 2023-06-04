#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
// 读取文本文件中的内容
char *readTextFile(char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error: cannot open file %s\n", filename);
    return NULL;
  }
  // 获取文件长度
  fseek(fp, 0, SEEK_END);
  long length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  // 读取文件内容
  char *content = (char *)malloc(length + 1);
  fread(content, 1, length, fp);
  content[length] = '\0';
  fclose(fp);
  return content;
}
// 写入文本文件
void writeTextFile(char *filename, char *content)
{
  FILE *fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("Error: cannot open file %s\n", filename);
    return;
  }
  fwrite(content, 1, strlen(content), fp);
  fclose(fp);
}
// 读取二进制文件中的内容
unsigned char *readBinaryFile(char *filename, long *lengthPtr)
{
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    printf("Error: cannot open file %s\n", filename);
    return NULL;
  }
  // 获取文件长度
  fseek(fp, 0, SEEK_END);
  long length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  // 读取文件内容
  unsigned char *content = (unsigned char *)malloc(length);
  fread(content, 1, length, fp);
  fclose(fp);
  *lengthPtr = length;
  return content;
}
// 写入二进制文件
void writeBinaryFile(char *filename, unsigned char *content, long length)
{
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL)
  {
    printf("Error: cannot open file %s\n", filename);
    return;
  }
  fwrite(content, 1, length, fp);
  fclose(fp);
}