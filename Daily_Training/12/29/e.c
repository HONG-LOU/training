#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char temp[100];
  FILE *file;

  if ((file = fopen("article.txt", "r")) == NULL) {
    printf("文件读取失败!");
    exit(1);
  }

  while ((fscanf(file, "%s", temp)) != EOF) {
    printf("%s\n", temp);
  }

  return 0;
}