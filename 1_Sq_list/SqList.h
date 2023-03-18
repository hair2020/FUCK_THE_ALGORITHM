
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10 // 增补空间

typedef struct 
{
    ElemType *elem;
    int length;
    int listSize;
    int inCrementSize;
}SqList;

void Init_sqlist(SqList &L,int maxSize=LIST_INIT_SIZE,int increment=LIST_INCREMENT){
    L.elem = (ElemType *) malloc(maxSize*sizeof(ElemType));
    if (!L.elem) exit(1);
    L.length = 0;
    L.listSize = maxSize;
    L.inCrementSize = increment;
}

int List_length(SqList L){
    return L.length;
}

bool List_empty(SqList L){
    if (L.length == 0) return true;
    return false;
}

// search e
int Locate_elem(SqList L,ElemType e){
    for (int i=0; i<L.length ; i++){
        if (L.elem[i] == e) return i;
    }
    return -1;
}

bool Listsq_insert(SqList &L,int i,ElemType e){
    if (i<0||i>L.length) return false;
    if (L.length >= L.listSize){
        L.elem = (ElemType *) realloc(L.elem,(L.listSize + L.inCrementSize)*sizeof(ElemType));
        if (!L.elem) exit(1);
        L.listSize += L.inCrementSize;
    }
    for (int j=L.length; j>i; j--){
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i] = e;
    L.length ++;
    return true;
}

// incremental insertion
bool Listsq_increse_insert(SqList &L,ElemType e){
    int i,j;
    if (L.length>= L.listSize){
        L.elem = (ElemType *)realloc(L.elem,(L.listSize+L.inCrementSize)*sizeof(ElemType));
        if (!L.elem) exit(1);
        L.listSize += L.inCrementSize;
    }
    for (i=0;i<L.length&&e>L.elem[i];i++);
    for (j=L.length;j>i;j--){
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i] = e;
    L.length ++;
    return true;
}

bool List_delete(SqList &L,int i,ElemType &e){
    if (i<0||i>L.length) return false;
    if (L.length <= 0) return false;
    e = L.elem[i];
    for (int j=i+1; j<L.length; j++){
        L.elem[j-1] = L.elem[j];
    }
    L.length --;
    return true;
}

bool Get_elem(SqList L,int i,ElemType &e){
    if (i<0||i>L.length) return false;
    if (L.length <= 0) return false;
    e = L.elem[i];
    return true;
}

void SqList_Traverse(SqList L){
    for (int i=0;i<L.length;i++){
        cout<<setw(10)<<L.elem[i]<<endl;
    }
}

void Destroy_Listsq(SqList &L){
    free(L.elem);
    L.elem == NULL;
    L.length = 0;
    L.listSize = 0;
}



