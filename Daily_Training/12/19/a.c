#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
typedef char ElemType;

typedef struct BiTreeNode
{
    ElemType data;
    struct BiTreeNode *LChild;
    struct BiTreeNode *RChild;
} BiTreeNode, *BiTree;

// void CreateBiTree(BiTree *T){
//     char ch;
//     scanf("%c",&ch);
//     if (ch=='#')
//         *T = NULL;
//     else{
//         *T = (BiTree )malloc(sizeof(BiTreeNode));
//         if(!*T)
//             exit(-1);
//         else{
//             (*T)->data = ch;
//             CreateBiTree(&(*T)->LChild);
//             CreateBiTree(&(*T)->RChild);
//         }
//     }
//     printf("finished\n");
// }

// BiTree CreateBiTree(){
//     char ch;
//     BiTree T;
//     scanf("%c",&ch);
//     if(ch=='#')
//         T = NULL;
//     else{
//         T = (BiTree)malloc(sizeof(BiTreeNode));
//         T->data = ch;
//         T->LChild = CreateBiTree();
//         T->RChild = CreateBiTree();
//     }
//     return T;
// }

// nzw create

int NodeID;

BiTree CreateBiTree(char *c, int n)
{
    NodeID++;
    if (NodeID > n)
    {
        return (NULL);
    }
    if (c[NodeID] == '#')
    {
        return (NULL);
    }
    BiTreeNode *T;
    T->data = c[NodeID];
    T->LChild = CreateBiTree(c, n);
    T->RChild = CreateBiTree(c, n);
    return (T);
}

void PreReserve(BiTreeNode *T)
{
    if (T)
    {
        printf("%d ", T->data);
        PreReserve(T->LChild);
        PreReserve(T->RChild);
    }
}

// void PreReserve(BiTreeNode *T){
//     BiTreeNode *stack1[MAXSIZE];
//     int top;
//     top = -1;
//     BiTreeNode *p = T;
//     while(p!=NULL||top!=-1){
//         if(p!=NULL){
//             top++;
//             stack1[top] = p;
//             printf("%c",p->data);
//             p = p->LChild;
//         }
//         else{
//             p = stack1[top];
//             top--;
//             p = p->RChild;
//         }
//     }
// }

void InReserver(BiTreeNode *T)
{
    BiTreeNode *stack1[MAXSIZE];
    int top;
    top = -1;
    BiTreeNode *p = T;
    while (p != NULL || top != -1)
    {
        if (p != NULL)
        {
            top++;
            stack1[top] = p;
            p = p->LChild;
        }
        else
        {
            p = stack1[top];
            top--;
            printf("%c", p->data);
            p = p->RChild;
        }
    }
}

void EndReserve(BiTreeNode *T)
{
    BiTreeNode *stack1[MAXSIZE];
    int flag[MAXSIZE]; // ?????????????????????????????????
    int top = -1;
    BiTreeNode *p = T;
    while (p != NULL || top != -1)
    {
        if (p != NULL)
        { // ?????????????????????flag=1?????????
            top++;
            stack1[top] = p;
            flag[top] = 1;
            p = p->LChild;
        }
        else
        {
            if (flag[top] == 1)
            { // ??????????????????flag=2????????????????????????
                p = stack1[top];
                flag[top] = 2;
                p = p->RChild;
            }
            else
            { // ????????????????????????
                p = stack1[top];
                top--;
                printf("%c", p->data);
                p = NULL;
            }
        }
    }
}

int PreOrderReserveLeaves(BiTreeNode *T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (T->LChild == NULL && T->RChild == NULL)
    {
        return 1;
    }
    return PreOrderReserveLeaves(T->LChild) + PreOrderReserveLeaves(T->RChild);
}

int GetTreeHeight(BiTreeNode *T)
{

    int L = 0, R = 0;
    if (T)
    {
        L = GetTreeHeight(T->LChild);
        R = GetTreeHeight(T->RChild);
        if (L > R)
            return L + 1;
        else
            return R + 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    BiTree T;
    int choice;
    while (1)
    {
        printf("**********************\n ");
        printf("1??????????????????\n ");
        printf("2???????????????\n ");
        printf("3???????????????\n ");
        printf("4???????????????\n ");
        printf("5???????????????????????????\n ");
        printf("6??????????????????\n ");
        printf("?????????:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("??????????????????");
            char a[100];
            NodeID = 0;
            int i;
            int num;
            scanf("%d", &num);
            for (i = 1; i <= num; i++)
            {
                scanf("%c", &a[i]);
            }
            T = CreateBiTree(a, num);
            printf("????????????????????????");
        }

        else if (choice == 2)
        {
            printf("???????????????????????????: ");
            PreOrderReserveLeaves(T);
        }

        else if (choice == 3)
        {
            InReserver(T);
        }

        else if (choice == 4)
        {
            EndReserve(T);
        }

        else if (choice == 5)
        {
            PreOrderReserveLeaves(T);
        }

        else if (choice == 6)
        {
            GetTreeHeight(T);
        }

        else
        {
            printf("??????! ???????????????\n");
        }
    }

return 0;
}