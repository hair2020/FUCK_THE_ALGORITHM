#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct {
    int *queue;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
} SqQueue;

void InitQueue_Sq(SqQueue &Q,int maxsize = 100,int incresize = 10){
    Q.queue = (int *) malloc (maxsize * sizeof(int));
    if (!Q.queue) exit(1);
    Q.rear = Q.front = 0;
    Q.queuesize = maxsize;
    Q.incrementsize = incresize;
}

int QueueLength_Sq(SqQueue Q){
    return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

bool EnQueue_Sq(SqQueue &Q,int e){
    // rear insert
    if ((Q.rear + 1) % Q.queuesize == Q.front){
        Q.queue = (int *)realloc(Q.queue,(Q.queuesize+Q.incrementsize)*sizeof(int));
        if (!Q.queue) return false;
        if (Q.front > Q.rear){ // ?
            for (int i=Q.queuesize; i >= Q.front; i--){
                Q.queue[i + Q.incrementsize] = Q.queue[i];
            }
            Q.front += Q.incrementsize;
        }
        Q.queuesize += Q.incrementsize;
    }
    Q.queue[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
    return true;
}

bool DeQueue_Sq(SqQueue &Q, int &e){
    if (Q.front == Q.rear) return false;
    e = Q.queue[Q.front]; // front out
    Q.front = (Q.front + 1) % Q.queuesize;
    return true;
}

bool GetHead_Sq(SqQueue &Q, int &e){
    if (Q.front == Q.rear) return false;
    e = Q.queue[Q.front];
    return true;
}

bool QueueEmpty_Sq(SqQueue &Q){
    return Q.front == Q.rear;
}

void DestroyQueue_Sq(SqQueue &Q){
    free(Q.queue);
    Q.queuesize = 0;
    Q.front = Q.rear = 0;
}

void visualization(SqQueue L, char* filename)
{   int temp;
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\nnode [shape = box];\n");  
	for(int i=0;i<L.queuesize;i++)
	if(DeQueue_Sq(L,temp))
    {
	    fprintf(stream, "box%d [label = \"%d\"];\n",i,temp);
	    if(i>0&&i<L.queuesize-1)
	    {
    		fprintf(stream, "box%d -> box%d;\n",i,i-1);	
    	}
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng showsqlist.dot -o showsqlist.png");
	system("showsqlist.png");
}
