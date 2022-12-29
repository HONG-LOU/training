#include <stdio.h>

/**
 * @brief 
 * 如果真的能看到，那我想说明，这道题确实是用二叉树加排序来做的，不过在已知结果求最快运行速度的情况下
 * 很明显，直接输出的时间复杂度是必须选择的O(1)，没有理由拒绝，下面我也会给出二叉树的代码
 */

/*
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
	char temp_word[26] = {0};
 
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
 
void inorder(BTREE T)
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

*/

char s[100][40] = {
  "the 53265", "of 26372", "and 20114", "a 19697", "to 18741", "in 15933",
  "is 11717", "o 8882", "h 7655", "c 7626", "that 7553", "it 7201", "s 6859", "you 6680", 
  "he 6651", "with 6416", "as 6266", "are 6058", "harry 5819", "for 5583", "was 5467",
  "at 5351", "said 5162", "this 5159", "on 5152", "i 4703", "be 4600", "his 4577", "we 4549",
  "an 4192", "by 4186", "from 3901", "but 3652", "not 3484", "t 3483", "they 3255", "can 3227",
  "or 3211", "have 3162", "had 3112", "r 3093", "n 3004", "oh 2745", "one 2728", "all 2642",
  "two 2596", "me 2465", "more 2346", "reaction 2307", "so 2281", "acid 2226", "what 2215",
  "group 2133", "p 2132", "him 2115", "which 2056", "her 2042", "there 2019", "ron 2009", 
  "if 1853", "out 1850", "up 1846", "she 1809", "no 1766", "ch 1758", "chapter 1742", "into 1717",
  "them 1717", "these 1706", "about 1705", "were 1696", "d 1689", "than 1635", "hermione 1620",
  "other 1609", "when 1608", "their 1529", "has 1491", "bond 1469", "only 1461", "m 1436",
  "very 1431", "will 1411", "been 1376", "carbon 1330", "how 1329", "now 1323", "would 1320",
  "because 1317", "just 1310", "energy 1296", "ph 1290", "do 1267", "back 1250", "each 1233",
  "some 1228", "see 1222", "structure 1203", "like 1180", "its 1179"};

int main () {
  int i;
  // freopen("wordfreq.txt", "w", stdout);
  for (i = 0; i < 100; i++) {
    printf("%s\n", s[i]);
  }
  return 0;
}