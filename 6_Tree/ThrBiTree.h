
// tag : 0 represents node ,1 represents thread
typedef struct ThreadedBiNode {
    TElemType data;
    ThreadedBiNode *lchild, *rchild;
    unsigned short int Ltag; // sign of left flag, 2Bytes
    unsigned short int Rtag;
}ThrBiNode, *ThrBiTree;

// Preorder assignment and generate threaded BT.
void CreatThrBiTree(ThrBiTree &BT) {
    TElemType a;
    cin >> a;
    if (a==Nil) {
        BT = NULL;
    }
    else {
        BT = (ThrBiTree) malloc (sizeof(ThrBiNode));
        if (!BT) exit(1);

        BT->data = a;
        CreatThrBiTree(BT->lchild);
        if (BT->lchild) {
            BT->Ltag = 0;
        }
        else { 
            BT->Ltag = 1;
        }
        CreatThrBiTree(BT->rchild);
        if (BT->rchild) {
            BT->Rtag = 0;
        }
        else {
            BT->Rtag = 1;
        }
    }
}

// global variable, point to the node that just visited
ThrBiNode *pre;

// inorder traversal for threading BT. Can't use directly, beacause pre is unknow;
void InThreading(ThrBiTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->Ltag = 1;
            p->lchild = pre;
        }
        if (!pre->rchild) {
            pre->Rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// Inorder traversal BT for threading inorder BT. Add head node.
void InThreading_head(ThrBiNode *head, ThrBiTree BT) {
    if ( !(head = (ThrBiNode *) malloc (sizeof(ThrBiNode)))) exit(1);
    head->Ltag = 0;
    head->Rtag = 1;
    head->rchild = head;
    if (!BT) {
        head->lchild = head;
    }
    else {
        head->lchild = BT;
        pre = head;
        InThreading(BT);

        pre->rchild = head;
        pre->Rtag = 1;
        head->rchild = pre;
    }
}