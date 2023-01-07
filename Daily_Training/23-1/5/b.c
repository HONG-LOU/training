/**
 *    author:  HONG-LOU
 *    created: 2023-01-05 09:13:51
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 200

typedef struct{
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *S){
	S->top = -1;
}

bool IsEmpty(SqStack S){
	if(S.top == -1){
		return true;
	}
	return false;
}

void Push(SqStack *S,char x){
	if(S->top == MaxSize-1){
		printf("full");
		return;
	}
	S->top += 1;
	S->data[S->top] = x;
}

void Pop(SqStack *S,char *x){
	if(S->top == -1){
		printf("full");
		return;
	}
	*x = S->data[S->top];
	S->top -= 1;
}

bool bracketCheck(char str[]){
	SqStack S;
	InitStack(&S);
  int length = strlen(str);
  int i;
	for(i=0;i<length;i++){
    if (str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '{' && str[i] != '}') {
      continue;
    }
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			Push(&S,str[i]);
		}else{
			if(IsEmpty(S)){
				return false;
			}
			char topElem;
			Pop(&S,&topElem);
			if(str[i]==')'&&topElem!='('){
				return false;
			}
			if(str[i]=='}'&&topElem!='{'){
				return false;
			}
			if(str[i]==']'&&topElem!='['){
				return false;
			}
		}
	}
	return IsEmpty(S);
}
int main(){
	char s[MaxSize];
	scanf("%s",s);
	if(bracketCheck(s)){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}

