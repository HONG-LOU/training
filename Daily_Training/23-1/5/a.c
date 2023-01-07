/**
 *    author:  HONG-LOU
 *    created: 2023-01-05 08:55:57
**/
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Node	 {
  elemtype id;
	elemtype score;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

int InitList(LinkList *L)	{
	(*L) = (LinkList)malloc(sizeof(Node));
	if (!L)
	{
		printf("wrong!~\n");
		exit(0);
	}
	(*L)->next = NULL;
	return 0;
}

void CreateListTail(LinkList *L) {
	int i, n;
	LinkList p,r;
	(*L) = (LinkList)malloc(sizeof(Node));
	r = *L;
  n = 3;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d, %d", &p->id, &p->score);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int LengthList(LinkList *L)	{
	int length = 0;
	LinkList p;
	p = (*L)->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

int GetElem(LinkList L, int i, elemtype *e, elemtype *ne) {
	int j = 1;
	LinkList p;
	p = L->next;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		printf("Not found!\n");
		return 0;
	}
	*e = p->id;
  *ne = p->score;
	return 0;
}

int InsertList(LinkList *L, int i, elemtype e, elemtype ne) {
	LinkList p, s;
	int j = 1;
	p = *L;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		printf("wrong!~\n");
		return 0;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->id = e;
  s->score = ne;
	s->next = p->next;
	p->next = s;
	return 0;
}

int DeleteList(LinkList *L, int i, elemtype *e, elemtype *ne)	{
	LinkList p, q;
	int j = 1;
	p = *L;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		printf("wrong!~\n");
		return 0;
	}
	q = p->next;
	p->next = q->next;
	*e = q->id;
  *ne = q->score;
	free(q);
	return 0;
}

int ClearList(LinkList *L) {
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 0;
}

void ShowList(LinkList *L) {
	LinkList p;
	p = (*L)->next;
	if (p == NULL)
	{
		printf("NULL\n");
	}
	while (p)
	{
		printf("[num=%d,score=%d]\n", p->id, p->score);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList L;
	InitList(&L);
	CreateListTail(&L);
	ShowList(&L);
	return 0;
}
