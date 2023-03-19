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

typedef BiTree ElemType;
#include "SqQueue.h"
// level order BT
void LevelOrderBiTree(BiTree BT, void Visit(TElemType)){
    SqQueue Q;
    BiTree p;
    if (BT) {
        InitQueue_Sq(Q,MAX_BITREE_SIZE,10);
        EnQueue_Sq(Q,BT);
        while (!QueueEmpty_Sq(Q)) {
            DeQueue_Sq(Q,p);
            Visit(p->data);
            if (p->lchild != NULL) {
                EnQueue_Sq(Q,p->lchild);
            }
            if (p->rchild != NULL) {
                EnQueue_Sq(Q,p->rchild);
            }
        }
    }
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

// if e isn't BT's root, return it's parent, else return null
BiTree Parent(BiTree BT, TElemType e){
    SqQueue Q;
    BiTree p;
    if (BT) {
        InitQueue_Sq(Q,MAX_BITREE_SIZE,10);
        EnQueue_Sq(Q,BT);
        while (!QueueEmpty_Sq(Q)) {
            DeQueue_Sq(Q,p);
            if (p->lchild && p->lchild->data == e || p->rchild && p->rchild->data == e){
                return p;
            }
            else {
                if (p->lchild){
                    EnQueue_Sq(Q,p->lchild);
                }
                if (p->rchild){
                    EnQueue_Sq(Q,p->rchild);
                }
            }
        }
    }
    return NULL;
}

// if e exist, return e's leftchild or null.
BiTree LeftChild(BiTree BT, TElemType e){
    BiTree p;
    if (BT) {
        p = SearchBiTree(BT,e);
        if (p) {
            return p->lchild;
        }
    }
    return NULL;
}

// if e exist, return e's rightchild or null.
BiTree RightChild(BiTree BT, TElemType e){
    BiTree p;
    if (BT) {
        p = SearchBiTree(BT,e);
        if (p) {
            return p->rchild;
        }
    }
    return NULL;
}

// if e exist, return e's left sibling or null.
BiTree LeftSibling(BiTree BT, TElemType e){
    BiTree p;
    if (BT) {
        p = Parent(BT,e);
        if (p && p->lchild && p->rchild && p->rchild->data == e){
            return p->lchild;
        }
    }
    return NULL;
}

// if e exist, return e's right sibling or null.
BiTree RightSibling(BiTree BT, TElemType e){
    BiTree p;
    if (BT) {
        p = Parent(BT,e);
        if (p && p->rchild && p->lchild && p->lchild->data == e){
            return p->rchild;
        }
    }
    return NULL;
}

// if BT exist, insert BT c as p node's child accroding to LR value
// c's right child is NULL
// LR = 0, c is left child
// LR = 1, c is right child
// return bool
bool InsertChild(BiTree p, int LR, BiTree c) {
    if (p) {
        if (LR == 0){ // left
            c->rchild = p->lchild;// remain p->lchild tree
            p->lchild = c;
        }
        else {
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return true;
    }
    return false;
}

// Print BT in the form of concave table
// n is the number of indent layers and the initial value is 1
void PrintBiTree(BiTree BT, int n) {
    int i;
    if (!BT) return;
    PrintBiTree(BT->rchild, n + 1);
    for (i = 2; i < n; ++i){
        cout << "   ";
    }
    if (n > 1) cout << " ---";
    cout << BT->data << endl;
    PrintBiTree(BT->lchild,n+1);
}

// Destory BiTree
void DestoryBiTree(BiTree &BT) {
    if (BT) {
        DestoryBiTree(BT->lchild);
        DestoryBiTree(BT->rchild);
        free(BT);
        BT = NULL;
    }
}

// if BT exists, p is a BT node, delete the p's subtree accroding to LR value
// LR = 0, delete left child
// LR = 1, delete right child
// return bool
bool DeleteChild(BiTree p, int LR) {
    if (p) {
        if (LR == 0) {
            DestoryBiTree(p->lchild);
        }
        else {
            DestoryBiTree(p->rchild);
        }
        return true;
    }
    return false;
}
