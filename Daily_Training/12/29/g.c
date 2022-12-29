#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 5000
typedef struct node{
	int count;
	char word[26];
	struct node *lchild, *rchild;  //建立节点的时候 每个节点有左孩子和右孩子 
}BTNode, *BTREE; 
int times = 0;
int summ = 0;
struct ww {
  int c;
  char w[26];
}*s;
int sum = 0;
int get_word(char *temp_word, FILE *in);
BTREE insert(BTREE T, char temp_word[]); // remember to return a pointer so it can change its real address
void inorder(BTREE root);
int main()
{
	char temp_word[26] = {0}; /*prepare to put the content of temp_word to real wordblock.word*/
 
   	FILE *in;
    int i,j;
 
	if( (in = fopen("article.txt", "r")) == NULL )
    printf("No such file!\n");
    
    BTREE root = NULL;        //每次insert 都是把根节点当作参数传进去的 
	while( !feof(in) )
	{
		char temp_word[26] = {0};
		get_word(temp_word,in);
		root = insert(root, temp_word);
	}

  int summ = cou(root);

  struct ww {
    int c;
    char w[26];
  }s[summ];
	
  inorder(root);

  char ce[26];

  for (i = 0; i < summ - 1; i++) {
    for (j = i + 1; j < summ; j++) {
      if (s[j].c > s[i].c) {
        int temp = s[i].c;
        s[i].c = s[j].c;
        s[j].c = temp;
        strcpy(ce, s[i].w);
        strcpy(s[i].w, s[j].w);
        strcpy(s[j].w, ce);
      }
      if (s[j].c == s[i].c && strcmp(s[i].w, s[j].w) > 0) {
        int temp = s[i].c;
        s[i].c = s[j].c;
        s[j].c = temp;
        strcpy(ce, s[i].w);
        strcpy(s[i].w, s[j].w);
        strcpy(s[j].w, ce);
      }
    }
  }

  for (i = 0; i < 100 && i < sum && s[i].c > 0; i++) {
    printf("%s %d\n", s[i].w, s[i].c);
  }
	
	return 0;
}
 
int get_word(char *temp_word, FILE *in)
{
	int i = 0; 
    char temp = '0';
    temp = fgetc(in);
	while( !isalpha(temp) )
    {
		temp = fgetc(in);
		if(temp==EOF)
		return 1;
	}
 
	while(isalpha(temp) && !isspace(temp) )	
	{
		temp = tolower(temp);
		temp_word[i] = temp;
		i++;
		temp = fgetc(in);
	}
 
    return 0;
}

int cou(BTREE T) {
  if (T == NULL) {
    return 0;
  }
  return cou(T -> lchild) + cou(T -> rchild) + 1;
}

BTREE insert(BTREE p, char temp_word[])
{
	int cond;
	if(p == NULL)
	{
		p = (BTREE)malloc(sizeof(BTNode));
		strcpy(p->word, temp_word);
		p->count = 1;
		p->lchild = p->rchild = NULL;
	}
 
	else if( (cond  = strcmp(temp_word, p->word)) == 0)
	{
		p->count++;
	}
	else if( cond<0 )
	{
		p->lchild = insert(p->lchild, temp_word);
	}
	else 
	{
		p->rchild = insert(p->rchild, temp_word);
	}
	return (p);
}
 
void inorder(BTREE T)  /*using inorder*/
{
	 if(T!= NULL)
    {	
    	inorder(T->lchild);
    
      s[sum].c = T -> count;
      strcpy(s[sum].w, T -> word);
      sum++;
    	inorder(T->rchild);
	}
}
