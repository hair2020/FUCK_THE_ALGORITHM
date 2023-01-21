#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

void InitBiTree(BiTree &BT){
    BT = NULL;
}

void CreateBiTree(BiTree &BT) {
    int a;
    cin >> a;
    if (a == 0) {
        BT = NULL;
    }
    else {
        BT = (BiTNode *) malloc (sizeof(BiTNode));
        if (!BT) exit(1);
        BT->data = a;
        CreateBiTree(BT->lchild);
        CreateBiTree(BT->rchild); 
    }
}

bool BiTreeEmpty(BiTree &BT) {
    if (BT) return false;
    return true;
}

int BiTreeDepth(BiTree BT) {
    int lh=0,rh=0;
    if (!BT) return 0;
    lh = BiTreeDepth(BT->lchild);
    rh = BiTreeDepth(BT->rchild);
    return lh>rh ? lh + 1:rh+1;
}



