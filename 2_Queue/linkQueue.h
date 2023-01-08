#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue_L(LinkQueue &Q){
    Q.front = NULL;
    Q.rear = NULL;
}

int QueueLength_L(LinkQueue &Q){
    QueuePtr p;
    p = Q.front;
    int k = 0;
    while (p) {
        k ++;
        p = p->next;
    }
    return k;
}

bool EnQueue_L(LinkQueue &Q, int e){
    QueuePtr s;
    s = (QueuePtr) malloc (sizeof(LNode));
    if (!s) return false;
    s->data = e;
    s->next = NULL;
    if (Q.rear == NULL){
        Q.front = Q.rear = s;
    } else {
        Q.rear = Q.rear->next = s;
    }
    return true;
}

bool DeQueue_L(LinkQueue &Q, int &e){
    QueuePtr p;
    if (!Q.front) return false;
    p = Q.front;
    e = p->data;
    Q.front = p->next;
    if (!Q.front) Q.rear = NULL; // 循环链队？
    free(p);
    return true;
}

bool GetHead_L(LinkQueue &Q, int &e){
    if (!Q.front) return false;
    e = Q.front->data;
    return true;
}

bool QueueEmpty_L(LinkQueue &Q){
    if (!Q.front) return true;
    return false;
}

bool DestroyQueue_L(LinkQueue &Q){
    QueuePtr p;
    while (Q.front){
        p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
    Q.front = Q.rear = NULL;
    return true;
}

void visualization(LinkQueue L, char* filename)//链式结构由于指针，不存在值传递 
{   int temp,queueLength;
	queueLength=QueueLength_L(L);
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\nnode [shape = box];\n");  
	for(int i=0;i<queueLength;i++)
	if(DeQueue_L(L,temp))
    {
	    fprintf(stream, "box%d [label = \"%d\"];\n",i,temp);
	    if(i>0&&i<queueLength)
	    {
    		fprintf(stream, "box%d -> box%d;\n",i,i-1);	
    	}
    	EnQueue_L(L,temp);//重新入队 ，链式结构由于指针，不存在值传递  
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng showsqlist.dot -o showsqlist.png");
	system("showsqlist.png");
}
