#include<stdio.h>
#include<string.h>
int main()
{
  char str1[100],str2[100],t[100];
  gets(str1);
  gets(str2);
  char *p;
  while((p=strstr(str1,str2))!=NULL)
  {
    strcpy(t,p+strlen(str2));
    *p='\0';
    strcat(str1,t);
  }
  puts(str1);
}
