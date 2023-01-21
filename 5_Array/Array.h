#define MAX_ARRAY_DIM 8
#include <stdarg.h>
#include <stdlib.h>
typedef struct 
{
    int *base;
    int dim;
    int *b; // dim 基址
    int *c; // 映象函数基址
}Array;

bool InitArray(Array &A,int dim, ...) {
    int elemTotal = 1 , i;
    va_list ap;
    if (dim < 1 || dim > MAX_ARRAY_DIM) return false;
    A.dim = dim;
    A.b = (int *) malloc (dim * sizeof(int));
    if (!A.b) exit(1);
    va_start(ap,dim);

    for (i=0; i < dim; ++i) {
        A.b[i] = va_arg(ap,int);
        if(A.b[i] < 0) return false;
        elemTotal *= A.b[i];
    }

    va_end(ap);
    A.base =(int *) malloc (elemTotal * sizeof(int));
    if (!A.base) exit(1);
    A.c[dim-1] = 1;

    for (i = dim - 2; i >= 0; --i) {
        A.c[i] = A.b[i+1] * A.c[i+1];
    }
    return true;
}
