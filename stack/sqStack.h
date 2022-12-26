#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct
{
    int *stack;
    int top;
    int stackSize;
    int incrementSize;
} SqStack;

void InitStack_Sq(SqStack &S,int maxSize=STACK_INIT_SIZE,int incrementSize=STACK_INCREMENT){
    S.stack = (int *) malloc(maxSize * sizeof(SqStack));
    if (!S.stack) exit(1);
    S.top = -1;
    S.incrementSize = incrementSize;
    S.stackSize = maxSize;
}

int StackLength_Sq(SqStack S){
    return S.top + 1;
}

bool Push_Sq(SqStack &S, int e){
    if (S.top == S.stackSize-1){
        S.stack = (int *) realloc (S.stack,(S.stackSize+S.incrementSize)
        * sizeof(int));
        if (!S.stack) return false;
        S.stackSize += S.incrementSize;
    }
    S.stack[++S.top] = e;
    return true;
}

bool Pop_Sq(SqStack &S,int &e){
    if (S.top == -1){
        return false;
    }
    e = S.stack[S.top--];
    return true;
}

bool GetTop_Sq(SqStack &S,int &e){
    if (S.top == -1){
        return false;
    }
    e = S.stack[S.top];
    return true;
}

bool StackEmpty_Sq(SqStack S){
    if (S.top==-1) return true;
    return false;
}

void DestroyStack_Sq(SqStack &S){
    free(S.stack);
    S.top = -1;
    S.stackSize=0;
    S.stack = NULL;
}
