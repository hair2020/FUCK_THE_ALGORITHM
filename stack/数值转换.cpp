#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "LinkStack.h"
void TransFrom(long num,int dec){
    LinkStack S;
    InitStack_L(S);
    while (num){
        Push_L(S,num % dec);
        num = num/dec;
    }
    int x;
    while (!StackEmpty(S)){
        Pop_L(S,x);
        cout << x;
    }
}
int main() {
    int num,dec;              // num存放十进制数，dec存放进制
    cout<<"输入一个十进制数：";
    cin>>num;
    cout<<"输入要转换的进制：";
    cin>>dec;  
    cout<<"转换后的"<<dec<<"进制数为："; 
    TransFrom(num,dec);                 // 调用数制转换函数
    return 0;
}