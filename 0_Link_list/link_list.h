
typedef struct Node {
    ElemType data;
    struct Node *next;
}LNode,*LinkList;

void InitList_L(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if (!L) exit(1);
    L->next = NULL;
}

int ListLength_L(LinkList L){
    int k=0;
    L = L->next;
    while (L){
        k++;
        L=L->next;
    }
    return k;
}

LNode *LocateElem_L(LinkList L,ElemType e){
    L = L->next;

    while (L&&L->data!=e){
        L = L->next;
    }
    return L;
}

// return 元素位置
int  LocateElem_L_2(LinkList L,ElemType e){
    int i=0;
    L = L->next;
    while (L&&L->data != e) {
        L = L->next;
        i++;
    }
    return i;
}

//在带有头结点的单链表L中的第i个结点之前插入元素e
bool ListInsert_L(LinkList &L,int i, ElemType e){
    LNode *s;
    int j;
    j = 0;
    while (L->next&&j<i-1){
        L = L->next;
        j++;
    }
    if (j!=i-1) return false; //第i个元素不存在
    if (!(s=(LNode *)malloc(sizeof(LNode)))) exit(1);
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}
// 删除带有头结点的单链表L中的第i个结点，并让e返回其值
bool ListDelete_L(LinkList &L,int i,ElemType &e){
    LNode *s;
    int j = 0;
    int Llength = ListLength_L(L);
    if (i<1&&i>Llength) return false; // 位置不合理
    while(L->next->next&&j<i-1){ // 寻找第i-1个节点
        L=L->next;
        j ++;
    }
    s = L->next;
    L->next = s->next;
    e = s->data;
    free(s);
    return true;
}

bool GetElem_L(LinkList L, int i, ElemType &e){
    int j=0;
    while (L->next&&j<i){ // search the i node
        L=L->next;
        j ++;
    }
    if (j!=i) return false;
    e = L->data;
    return true;
}

// 已知一维数组A[n]中存有线性表的数据元素，利用头插法创建单链表L
void CreateList_L_Front(LinkList &L,ElemType a[],int n){
    LNode *p;
    int i;
    if (!(L = (LinkList) malloc( sizeof(LNode)))) exit(1);
    L->next = NULL;
    for (i=n-1;i>=0;i--){
        p = (LNode *) malloc (sizeof(LNode));
        // 懒得写分配失败了
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

// 尾插
void CreateList_L_Rear(LinkList &L, ElemType a[], int n){
    LNode *s;
    L = (LinkList) malloc(sizeof(LNode));
    // ...
    for (int i=0;i>n;i++){
        s = (LNode *) malloc (sizeof(LNode));
        // ..
        s->data = a[i];
        L->next = s;
        L = s;
    }
    L->next = NULL;
}

void ListTraverse_L(LinkList L){
    LinkList p = L->next;
    int c = 0;
    while (p&&c<10){
        cout << std::setw(6) << p->data <<endl;
        p = p->next;
        c ++;
    }
}

void DestroyList_L(LinkList &L){
    LNode *p;
    p = L;
    while (p){
        p = p->next;
        free(p);
    }
    L=NULL;
}