#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct LNode
{
    char str;
    struct LNode *next;
}SNode, *SLinkString;

// 赋值
void StrAssign_L(SLinkString &S, char *chars){
    SLinkString p = NULL,q = NULL;
    S = (LNode *)malloc (sizeof(LNode)); // 为啥'\r'会赋值给S.str
    if (!(*chars)) {
        S->next = NULL;
    } else {
        q = S;
        while (*chars)
        {
            p = (LNode *) malloc (sizeof(LNode));
            p->str = *chars;
            q->next = p;
            q = p;
            chars ++;
        }
        p->next = NULL;
    }
}

void StrCopy_L(SLinkString &S, SLinkString &T) {
    SLinkString p,q,r;
    while (S->next) {
        p = S;
        S = S->next;
        free(p);
    }
    r = T->next;
    p = S;
    while (r) {
        q = (LNode *) malloc (sizeof(LNode));
        if (!p) exit(0);
        q->str = r->str;
        p->next = q;
        p = q;
        r = r->next;
    }
    p->next = NULL;
}

int StrLength_L(SLinkString &S){
    int n = 0;
    LNode *p = S->next;
    return n;
}

/*
s>t 1
s<t -1
s=t 0
*/
int StrCompare_L(SLinkString &S, SLinkString &T){
    SLinkString p = S->next,q = T->next;
    while (p&&q) {
        if (p->str > q->str) return 1;
        else if (p->str < q->str) return -1;
        p = p->next;
        q = q->next;
    }
    if (p) return 1;
    if (q) return -1;
    return 0;
}

bool StrConcat_L(SLinkString &S,SLinkString &T) {
    SLinkString p, q = S->next, r = T->next;
    while (q->next) q = q->next;
    while (r) {
        p = (LNode *) malloc (sizeof(LNode));
        if (!p) return false;
        p->str = r->str;
        q->next = p;
        q = p;
        r = r->next;
    }
    q->next = NULL;
    return true;
}

void StrTraverse_L(SLinkString &S) {
    SLinkString p = S->next;
    while (p) {
        std::cout << p->str;
        p = p->next;
    }
    std::cout << endl;
}