#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "SqList.h"
void CreateList_Sq(SqList &L, int a[], int aLength){
    int i = 0;
    if (L.length==0){
        for (i;i<aLength;i++){
            Listsq_insert(L,i,a[i]);
        }
    }
}

bool Isequal(SqList La, SqList Lb){
    if (La.length != Lb.length) {
        return false;
    } else {
        for (int i=0;i<La.length;i++){
            if (Locate_elem(Lb,La.elem[i]) == -1){
                return false;
            }
        }
        return true;
    }
}

int main() {
    SqList La,Lb;
    int i,j,temp;
    int a[]={1,2,3,5};
    int b[]={2,3,5,1};
    Init_sqlist(La);
    Init_sqlist(Lb);
    CreateList_Sq(La,a,sizeof(a)/sizeof(a[0]));
    CreateList_Sq(Lb,b,sizeof(b)/sizeof(b[0]));
    if (Isequal(La,Lb)){
        cout<<"equal"<<endl;
    }else{
        cout<<"unequal"<<endl;
    }
    return 0;
}