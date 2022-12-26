#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;

}SNode,* LinkStack;

void InitStack(LinkStack &S){
    S = NULL;
}

int StackLength(LinkStack S){
    int k=0;
    while (S){
        k++;
        S=S->next;
    }
    return k;
}

bool Push(LinkStack &S,int e){
    LinkStack p;
    p=(SNode *)malloc(sizeof(SNode));
    if (!p){
        printf("fail malloc");
        return false;
    }
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

bool Pop(LinkStack &S,int &e){
    LinkStack p;
    if (S){
        p = S;
        S = S->next;
        e = p->data;
        free(p);
        return true;
    }else{
        return false;
    }
}

bool GetTop(LinkStack &S,int &e){
    if (S){
        e = S->data;
        return true;
    }else{
        return false;
    }
}

bool StackEmpty(LinkStack S){
    if (!S)
        return true;
    else
        return false;
}

void DestroyStack(LinkStack &S){
    LinkStack p;
    while (S){
        p = S;
        S = S->next;
        free(p);
    };
    S = NULL;
}
int main() {
    LinkStack S;
    InitStack(S);
    Push(S,2);
    Push(S,3);
    Push(S,5);
    int e;
    Pop(S,e);
    printf("pop: %d\n",e);
    int len = StackLength(S);
    printf("length: %d\n",len);
    DestroyStack(S);
    len = StackLength(S);
    printf("length: %d\n",len);
    return 0;
}