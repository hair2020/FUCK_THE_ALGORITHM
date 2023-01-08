#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} *LinkStack;

void InitStack_L(LinkStack &S){
    S = NULL;
}

int StackLength_L(LinkStack S){
    int n=0;
    while (S){
        S=S->next;
        n++;
    }
    return n;
}

bool Push_L(LinkStack &S,int e){
    LinkStack p;
    p = (Node *) malloc(sizeof(Node));
    if (!p) return false;
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

bool Pop_L(LinkStack &S,int &e){
    LinkStack p;
    p = S;
    if (p){
        e = p->data;
        S = S->next;
        free(p);
        return true;
    }
    return false;
}

bool GetTop_L(LinkStack S, int &e){
    if (S){
        e = S->data;
        return true;
    }
    return false;
}


bool StackEmpty(LinkStack S){
    if (!S) return true;
    return false;
}

void DestroyStack_L(LinkStack &S){
    LinkStack p;
    while (S){
        p = S;
        S = S->next;
        free(p);
    }
    S = NULL;
}