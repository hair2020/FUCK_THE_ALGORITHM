#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "SqList.h"

void CreateList_Sq(SqList &L, int a[],int aLength){
    int i = 0;
    if (L.length==0) {
        for (i;i<aLength;i++){
            Listsq_insert(L,i,a[i]);
        }
    }
}

void Purge(SqList &La,SqList &Lb, int &e)
{
    while(!List_empty(Lb))
    {
        List_delete(Lb,0,e);
        if(Locate_elem(La,e)==-1)
           Listsq_insert(La,La.length,e);
    }
    Destroy_Listsq(Lb);
}

int main()
{	
	int temp;
	SqList Lb;
	Init_sqlist(Lb, 30, 5);
	int a[6] = {3,2,2,1,7,8};
    int aLength = sizeof(a)/sizeof(a[0]);
	CreateList_Sq(Lb,a,aLength);
    cout<<"Lb:"<<endl;
    SqList_Traverse(Lb);
    
    SqList La;
    Init_sqlist(La, 30, 5);
    cout<<"La:"<<endl;
    SqList_Traverse(La);
    cout<<"Purge Lb"<<endl;
    Purge(La, Lb, temp);
    cout<<"La:"<<endl;
    SqList_Traverse(La);
    cout<<"Lb:"<<endl;
    SqList_Traverse(Lb);
    return 0; 
}	