#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
typedef int ElemType;
#include "SqList.h"

int main() {
    SqList mylist;
    int i,j,temp,forLocate,forGet,forInsert,forDelete;
    
    Init_sqlist(mylist, 50, 10);  
    for(i=0,j=1;i<10;i++,j++)
    if(!Listsq_insert(mylist,i, 2*j))
    {cout<<"错误!"<<endl; return 0;}
    cout<<"我创建了一个顺序表，表长为："<<List_length(mylist)<<endl;
    cout<<endl<<"表中的元素依次为："<<endl;
    SqList_Traverse(mylist);
    
    cout<<endl<<"***现在执行元素定位操作,请输入需要查找的元素：***"<<endl;
    cin>>forLocate;
    j=Locate_elem(mylist, forLocate);
    if(j!=-1) cout<<"找到了，它是第"<<j+1<<"个元素。"<<endl;
    else cout<<"定位失败！"<<endl;
    
    cout<<endl<<"***现在执行取元素操作,您要找第几个元素？请输入：***"<<endl;
    cin>>forGet;
    if(Get_elem(mylist,forGet-1,temp))  
    cout<<"第"<<forGet<<"个元素的值是:"<<temp<<endl;
    else cout<<"取元素失败！"<<endl;
    
    
    cout<<endl<<"***现在执行插入操作,您要将什么元素插入顺序表？请输入：***"<<endl;
    cin>>forInsert;
    cout<<"***插入到第几个位置？***"<<endl;
    cin>>temp;
    if(!Listsq_insert(mylist, temp-1, forInsert))
    {cout<<"插入!"<<endl; return 0;} 
    else cout<<"插入成功，插入后的顺序表为："<<endl;
    SqList_Traverse(mylist);
    
    cout<<endl<<"***现在执行删除操作,您要删除第几个元素？请输入：***"<<endl;
    cin>>forDelete;
    if(!List_delete(mylist,forDelete-1,temp))
    {cout<<"删除失败!"<<endl; return 0;} 
    else cout<<"删除成功，删除后的顺序表为："<<endl;
    SqList_Traverse(mylist);
    
    //  visualization(mylist,"showsqlist.dot");
    
    cout<<endl<<"***现在执行撤销操作***"<<endl;
    Destroy_Listsq(mylist);

    cout<<"***顺序表已经销毁！***"<<endl;
    return 0;
}