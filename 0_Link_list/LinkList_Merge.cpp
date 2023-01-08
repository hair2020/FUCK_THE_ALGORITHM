#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "link_list.h"

// insert element e in the linklist rear 
bool LK_insert(LinkList &L,int e){
    LNode *s;
    s = (LNode *) malloc(sizeof(LNode));
    if (!s) return false;
    s->data = e;
    s->next = NULL;
    while (L->next) L = L->next;
    L->next = s;
    return true;
}

// 归并两个带头结点非递减有序的单链表La和lb成为一个带头结点非递减有序的单链表Lc
void MergeLinkList(LinkList &A,LinkList &B,LinkList &C){
    A = A->next;
    B = B->next;
    int count = 0;
    while (A&&B){
        if(A->data <= B->data){
            LK_insert(C,A->data);
            A = A->next;
        }else{
            LK_insert(C,B->data);
            B = B->next;
        }
        count ++;
    }
    if (A) C->next = A;
    if (B) C->next = B;
}

int main() {
    LinkList A,B,C;
    InitList_L(A);
    InitList_L(B);
    InitList_L(C);
    LNode *heada = A,*headb = B,*headc = C;
    int a[] = {1,4,6,9,99};
    int b[] = {2,4,7};
    int fa=0,fb=0;
    for (int i=1,j=1;;i++,j++){
        if (i<=(sizeof(a)/4)){
            if (!LK_insert(A,a[i-1])){
                cout << "insert a failed" <<endl;
            }
        }else{
            fa = 1;
        }
        if (j<=(sizeof(b)/4)){
            if (!LK_insert(B,b[j-1])){
                cout << "insert b failed" <<endl;
            }
        }else{
            fb = 1;
        }
        if (fa&&fb) break;
    }
    A = heada; B = headb;
    cout << " A: \n";
    ListTraverse_L(A);
    cout << " B: \n";
    ListTraverse_L(B);

    MergeLinkList(A,B,C);
    cout << "After merging : \n";
    C = headc;
    ListTraverse_L(C);
    DestroyList_L(C);
    return 0;
}