#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElemType;

#include "LinkStack.h"

int main() {
    LinkStack S;
    InitStack_L(S);
    Push_L(S,2);
    Push_L(S,3);
    Push_L(S,5);
    int e;
    Pop_L(S,e);
    printf("pop: %d\n",e);
    int len = StackLength_L(S);
    printf("length: %d\n",len);
    DestroyStack_L(S);
    len = StackLength_L(S);
    printf("length: %d\n",len);
    return 0;
}