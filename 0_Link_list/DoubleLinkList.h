
typedef struct DuNode
{
    ElemType data;
    struct DuNode *prior;
    struct DuNode *next;
}DuLNode,*DuLinkList;

void InitList_DuL(DuLinkList &L){
    L = (DuLinkList) malloc (sizeof(DuLNode));
    if (!L) exit(1);
    L->next = NULL;
    L->prior = NULL;
}

int ListLength_Dul(DuLinkList L){
    int k = 0;
    L = L->next;
    while (L){
        k++;
        L->next;
    }
    return k;
}

// insert element e before i-th node in the bidirectional list L of the leader node
bool ListInsert_DuL(DuLinkList &L,int i,ElemType e){
    DuLNode *p,*s,*q;
    int j;
    q = L;
    j = 0;

    while (q->next&&j<i-1){ // find the (i-1)-th node
        j ++;
        q = q->next;
    }
    if (j!=i-1) return false;

    s = (DuLNode *) malloc (sizeof(DuLNode));
    if (!s ) exit(1);
    s->data = e;
    if (q->next){ // the insert position isn't the end of table  
        p = q->next; // p is the i-th node
        p->prior = s;

        s->next = p->next;
        s->prior = q;

        q->next = s;
    } else {
        s->next = NULL;
        s->prior = q;
        q->next = s;
    }
    return true;
}

// delete the i-th node
bool ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
    DuLNode *s;
    s = L;
    int j = 0;
    while (s->next&&j<i){
        s = s->next;
        j ++;
    }
    if (j!=i) return false;
    e = s->data;
    if (s->next){
        s->prior->next = s->next;
        s->next->prior = s->prior;
    } else {
        s->prior->next = NULL;
    }
    free(s);
    return true;
}

