#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
# include "SqStack.h"

void Print(SqStack S,int w[],int n)
{        
	int k=S.top;
	while(k>=0){
	    cout<<w[S.stack[k--]]<<' ';
    }
    cout<<endl;
}

void knapsack( int w[], int T, int n ) 
{   // 已知n件物品的体积分别为 w[0], w[1], …, w[n]，背包的总体积为 T,
    // 本算法输出所有恰好能装满背包的物品组合解
    SqStack S;
    int k=0;
	InitStack_Sq(S);
    do {
        while (T>0 && k<n) {
            if ( (T-w[k]) >= 0){
                Push_Sq(S,k);
                T -= w[k];
            }
            k ++;
        }
        if (T==0) Print(S,w,n);
        Pop_Sq(S,k);
        T += w[k];
        k++;
    }while (!StackEmpty_Sq(S)||k!=n);
}

int main(){
    int w[]={1,8,4,3,5,2},T=10;  // 背包总体积为10
    knapsack(w,T,6);
}