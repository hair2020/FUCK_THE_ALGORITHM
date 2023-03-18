typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

// visit bt
void Visit(TElemType e){
   
   cout<<e<<' ';
}

// BT == NULL
void InitBiTree(BiTree &BT){
    BT = NULL;
}

// preorder traversal
void PreOrderBiTree(BiTree BT, void Visit(TElemType)){
    
    if(BT){
        Visit(BT->data);
        PreOrderBiTree(BT->lchild,Visit);
        PreOrderBiTree(BT->rchild,Visit);
    }
}

typedef BiTree ElemType; // BT is type of BiTree.
#include "sqStack.h"
// use stack non-recursive to traversal preorder BT
void NRPreOrderBiTree(BiTree BT, void Visit(TElemType)){
    
    SqStack S;
    InitStack_Sq(S,MAX_BITREE_SIZE,10);
    while (BT || !StackEmpty_Sq(S)){
        if (BT) {
            Visit(BT->data);
            Push_Sq(S,BT);
            BT = BT->lchild;
        }
        else {
            Pop_Sq(S,BT);
            BT = BT->rchild;
        }
    }
}

// inorder traverse BT
void InOrderBiTree(BiTree BT, void Visit(TElemType)){
    
    if (BT){
        InOrderBiTree(BT->lchild,Visit);
        Visit(BT->data);
        InOrderBiTree(BT->rchild,Visit);
    }
}

// use stack traverse inorder BT
void NRInOrderBiTree(BiTree BT, void Visit(TElemType)){
    SqStack S;
    InitStack_Sq(S,MAX_BITREE_SIZE,10);
    while (BT || !StackEmpty_Sq(S)){
        if (BT) {
            Push_Sq(S,BT);
            BT = BT->lchild;
        }
        else {
            Pop_Sq(S,BT);
            Visit(BT->data);
            BT = BT->rchild;
        }
    }
}

// traverse postorder BT
void PostOrderBiTree(BiTree BT, void Visit(TElemType)){
    if (BT) {
        PostOrderBiTree(BT->lchild,Visit);
        PostOrderBiTree(BT->rchild,Visit);
        Visit(BT->data);
    }
}

// use stack traverse postorder BT (non-recursive)
void NRPostOrderBiTree(BiTree BT, void Visit(TElemType)){
    SqStack S;
    InitStack_Sq(S,MAX_BITREE_SIZE,10);
    BiTree p,q;
    int flag;
    if (!BT) return;
    p = BT;
    do {
        while (p) {
            Push_Sq(S,p);
            p = p->lchild;
        }
        q = NULL; flag = 1;
        while (!StackEmpty_Sq(S) && flag){
            GetTop_Sq(S,p);
            if (p->rchild == q){
                Pop_Sq(S,p);
                Visit(p->data);
                q = p;
            }
            else {
                p = p->rchild;
                flag = 0;
            }
        }
    } while (!StackEmpty_Sq(S));
}

// build a BT with preorder
void CreateBiTree(BiTree &BT) {
    TElemType a;
    cin >> a;
    if (a == Nil) {
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


// if it's empty return true
bool BiTreeEmpty(BiTree &BT) {
    if (BT) return false;
    return true;
}

// return BT depth(int)
int BiTreeDepth(BiTree BT) {
    
    int lh=0,rh=0;
    if (!BT) return 0;
    lh = BiTreeDepth(BT->lchild);
    rh = BiTreeDepth(BT->rchild);
    return lh>rh ? lh + 1:rh+1;
}

// search BT value equal to e
BiTree SearchBiTree(BiTree BT, TElemType e){
    
    BiTree t;
    if (!BT) return NULL;
    if (BT->data == e) return BT;
    // recursively find
    if (BT->lchild){
        t = SearchBiTree(BT->lchild,e);
        if (t) return t;
    }
    if (BT->rchild){
        t = SearchBiTree(BT->rchild,e);
        if (t) return t;
    }
    return NULL;
}

// if e isn't BT's root, return it's parents, else return null
BiTree Parent(BiTree BT, TElemType e){
    

}


