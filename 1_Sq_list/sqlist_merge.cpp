#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "SqList.h"
// 归并两个非递减有序的顺序表La和lb成为一个非递减有序的顺序表Lc
void MergeList_Sq(SqList La,SqList Lb, SqList &Lc){
    int i=0,j=0,k=0;
    int temp;
    Init_sqlist(Lc,La.listSize+Lb.listSize,LIST_INCREMENT);
    while (i<La.length&&j<Lb.length){
        if (La.elem[i]>=Lb.elem[j]){
            temp = Lb.elem[j++];
        }else{
            temp = La.elem[i++];
        }
        Lc.elem[k++] = temp;
    }
    while (i<La.length) Lc.elem[k++] = La.elem[i++];
    while (j<Lb.length) Lc.elem[k++] = Lb.elem[j++];
    Lc.length = La.length + Lb.length;
}

int main(){ 
    SqList La,Lb,Lc;
    int a[]={2,6,9,13,45};
    int b[]={1,6,19,25,45,60};
    Init_sqlist(La, 50,10);       
    Init_sqlist(Lb, 50,10);
    int fa=0,fb=0;
    for (int i=0,j=0;;i++,j++){
        if (i<(sizeof(a)/sizeof(a[0]))){
            if (!Listsq_insert(La,i,a[i])){
                cout<<"La insert failed"<<endl;
            }
        }else{
            fa = 1;
        }
        if (j<(sizeof(b)/sizeof(b[0]))) {
            if (!Listsq_insert(Lb,j,b[j])) {
                cout<<"Lb insert failed"<<endl;
            }
        }else{
            fb = 1;
        }
        if (fa&&fb) break;
    }

    cout << "La: \n";
    SqList_Traverse(La);
    cout << "Lb: \n";
    SqList_Traverse(Lb);
    MergeList_Sq(La,Lb,Lc);
    cout<<"merged Lc: \n";
    SqList_Traverse(Lc);       
}   