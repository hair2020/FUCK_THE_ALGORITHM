#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "SqList.h"

void Union(SqList &La,SqList Lb, int &e){
    while (!List_empty(Lb)){
        List_delete(Lb,0,e);
        if (Locate_elem(La,e) == -1){
            Listsq_insert(La,La.length,e);
        }
    }
    Destroy_Listsq(Lb);
}

int main() {
    SqList La,Lb;
    int i,j,temp;
    Init_sqlist(La,100,10);
    Init_sqlist(Lb,100,10);
    for (i=0,j=1;i<10;i++,j++){
        Listsq_insert(La,i,2*j);
        Listsq_insert(Lb,i,4+2*j);
    }
    SqList_Traverse(La);
    cout << "La end \n Lb :" << endl;
    SqList_Traverse(Lb);

    Union(La,Lb,temp);
    cout << "after union" <<endl;
    SqList_Traverse(La);

    return 0;
}