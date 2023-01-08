#include <stdio.h>
#include <stdlib.h>

struct  LNode
{
    int data;
    struct LNode *next;
};

typedef struct LNode LNode;
typedef struct LNode *LinkList;

bool InitList(LinkList &L);
LNode * GetELem(LinkList L,int i);
LinkList List_HeadInsert(LinkList &L);

bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if (L==NULL)
        return false;
    L->next = NULL;
    return true;
}

bool ListInsert(LinkList &L,int i, int e){
    if (i<1)
        return false;
    LNode *p;
    int j = 0; // position
    p = L;
    while (p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

void main(){
    LinkList L;
    InitList(L);
}
