#include <bits/stdc++.h>
using namespace std;

//本题采用循环链表解决 约瑟夫环问题 
typedef struct node{
	int	alive;
	node *next;
}*pnode; 

void init(pnode &head)
{
	head = new node;
	head->alive=-1;//头结点不参与计数 
	head->next=NULL;
}

void build(pnode head,int n)
{
	pnode p=head;
	for(int i=1;i<=n;i++)//为使链表依次从小到大，采用尾插法 
	{
		pnode a=new node;
		a->alive=i;
		head->next=a;
		a->next=NULL;
		if(n==i) a->next=p->next;//这里采用的是带头结点的循环链表表示形式 
		head=a;
	} 	
	//head=p;  这里形参head若是指针的引用 \
	这个函数中关于head的操作会影响到其实际的值 ,这样就要加上前面那条语句 
}

void delete_node(pnode pre,pnode p)
{
	pre->next=p->next;
	p->next=NULL;
	delete p;
}

pnode find(pnode p,int k)
{
	pnode pre=NULL;
	while(k--)
	{
		pre=p;
		p=p->next;
	}
	if(p)
	{
		cout<<p->alive<<" ";
		delete_node(pre,p);
	}
	return pre;
}


void ysf(pnode head,int sum,int k)
{
	pnode p=head;
	while(sum>15)//这里15可根据实际情况调节
	{
		p=find(p,k);
		sum--;
	} 
} 
int main()
{
	pnode head=NULL;//node* head
	init(head);
	int n,k;
	cin>>n>>k;
	cout<<&head<<endl;
	build(head,n);  
	cout<<&head<<endl;
	ysf(head,n,k);//头指针  开始总人数  报数上限 
}
