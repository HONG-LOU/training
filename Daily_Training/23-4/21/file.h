#ifndef FILE_H
#define FILE_H
// 读取文本文件中的内容
char *readTextFile(char *filename);
// 写入文本文件
void writeTextFile(char *filename, char *content);
// 读取二进制文件中的内容
unsigned char *readBinaryFile(char *filename, long *lengthPtr);
// 写入二进制文件
void writeBinaryFile(char *filename, unsigned char *content, long length);
#endif