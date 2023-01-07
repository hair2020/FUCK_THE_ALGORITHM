#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct 
{
    char* str;
    int length;
}DSqString; // Dynamic Sequence string

bool StrAssign_Sq(DSqString &S,char *chars) {
    int charLength,i;
    char *c;
    for (charLength=0,c=chars;*c;charLength++,c++); // 最后一位'\000'
    if(!charLength) {
        S.str = NULL;
        S.length = 0;
    } else {
        S.str = (char *)malloc(charLength * sizeof(char));
        if (!S.str) return false;
        for (i = 0; i < charLength; i ++) {
            S.str[i] = chars[i];
        }
        S.length = charLength;
    }
    return true;
}

bool StrCopy_Sq(DSqString &S, DSqString T) {
    int i;
    if (S.str) free(S.str);
    if (!T.length) {
        S.str = NULL;
        S.length = 0;
    } else {
        S.str = (char *)malloc(T.length * sizeof(char));
        if (!S.str) return false;
        for (i=0;i<T.length;i++){
            S.str[i] = T.str[i];
        }
        S.length = T.length;
    }
    return true;
}

int StrLength_Sq(DSqString &S) {
    return S.length;
}

int StrCompare_Sq(DSqString &S, DSqString &T) {
    int i;
    while (i<S.length && i<T.length) {
        if (S.str[i] > T.str[i]) return 1;
        else if (S.str[i] < T.str[i]) return -1;
        i ++;
    }
    if (i<S.length) return 1;
    else if (i<T.length) return -1;
    return 0;
}

bool StrContact_Sq(DSqString &S, DSqString T){
    int i;
    if (T.length) {
        S.str = (char *) realloc (S.str,(S.length + T.length) * sizeof(char));
        if (!S.str) return false;
        for (i=0;i<T.length;i++) {
            S.str[S.length + i] = T.str[i];
        }
        S.length += T.length;
    }
    return true;
}

// pos start at 0
bool SubString_Sq(DSqString &S, DSqString &Sub, int pos, int len) {
    int i;
    if (pos<0 || pos>S.length-1 || len<0 || len>S.length-pos){
        return false;
    }
    if (Sub.str) {free(Sub.str);}
    if (!len) {
        Sub.str = NULL;
        Sub.length = 0;
    } else {
        Sub.str = (char *) malloc (len * sizeof(char));
        if (!Sub.str) return false;
        for (i=0; i<len; i++) {
            Sub.str[i] = S.str[pos + i];
        }
        Sub.length = len;
    }
    return true;
}

// pos start at 0
bool Indext_Sq(DSqString &S, DSqString &T, int &pos){
    int j = 0, i = 0;
    while (i<S.length && j<T.length){
        if(S.str[i] == T.str[j]){
            i++; j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length) {
        pos = i - T.length;
        return true;
    }
    return false;
}

// pos strat at 0
bool StrInsert_Sq(DSqString &S, int pos, DSqString &T) {
    int i = 0;
    if (pos < 0 && pos > T.length) return false;
    if (T.str){
        S.str = (char *) realloc (S.str,(S.length + T.length) * sizeof (char));
        if (!S.str) return false;
        for (i = S.length - 1; i >= pos; i --) {
            S.str[i+T.length] = S.str[i]; 
        }
        for (i = 0; i < T.length; i ++){
            S.str[pos + i] = T.str[i];
        }
        S.length += T.length;
        return true;
    }
}

// pos start at 0
bool StrDelete_Sq(DSqString &S, int pos, int len) {
    int i;
    if (pos < 0 || pos > S.length || len < 0 || pos + len > S.length) return false;
    for (i = pos+len; i < S.length; i++){
        S.str[i-len] = S.str[i];
    }
    S.str = (char *) realloc ( S.str,(S.str,(S.length - len) * sizeof(char)));
    if (!S.str) return false;
    S.length -= len;
    return true;
}

