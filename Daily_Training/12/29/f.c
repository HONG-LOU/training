#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct S_word
{
    int num;
    char a[15];// 单词的长度
};
int main()
{
    struct S_word W[10101]; //定义一个结构体W
    int i,m,n,k;
    char b[20];  // 用来和a【10】交换的数组
    FILE *fp;    // 定义文件
    char ch;     //从文件中读取字符
    int flag=0;  //标志空格后面是否有单词
    int j=0;    
    int temp;   //排时交换用
    char filename[20];
/****************首先将出现次数均设置为1****************************/
    for(i=0;i<10101;i++)
    {    W[i].num=1;
    }
        i=0;
/****************首先将出现次数均设置为1****************************/
/****************打开文件****************************/
    strcpy(filename, "article.txt");
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("error opening!");
        exit(0);
    }
/****************打开文件****************************/
/****************读取文件内容****************************/
   while(!feof(fp))
   {       
            ch=fgetc(fp);
            W[i].a[j]='\0';
            if (ch >= 65 && ch <= 90) {
              ch += (97 - 65);
            }
            if(ch>=97&&ch<=122)
            {
            W[i].a[j]=ch;                                       //识别单词
            j++;
            flag=1;
            }
            else if((ch==' ' || ch == '.' || ch == ';')&&flag==1)
            {   
                flag=0;
                j=0;
                  n=i;
                i++;
            if(n>=1)                                     //每一个单词跟前面的比较，如果相同就使次数加一
            {
                for(m=0;m<n;m++)
                {
                    if(strcmp(W[n].a,W[m].a)==0)
                    {                                
                        W[m].num++;
                        i=i-1;                           //如果单词相同则认为是一个单词
                    }
                }                     
            }
            }
   }
/****************根据单词出现次数进行排序***************************/  
     for (j = 0; j < i - 1; j++) {
      for (n = j + 1; n < i; n++) {
        if (W[n].num > W[j].num) {
          temp = W[n].num;
          W[n].num = W[j].num;
          W[j].num = temp;
          strcpy(b, W[j].a);
          strcpy(W[j].a, W[n].a);
          strcpy(W[n].a, b);
        }
        if (W[n].num == W[j].num && strcmp(W[n].a, W[j].a) < 0) {
          temp = W[n].num;
          W[n].num = W[j].num;
          W[j].num = temp;
          strcpy(b, W[j].a);
          strcpy(W[j].a, W[n].a);
          strcpy(W[n].a, b);
        }
      }
     }
     for (n = 0; n < i && n <= 99; n++) {
      printf("%s %d\n", W[n].a, W[n].num);
     }
    return 0;

}