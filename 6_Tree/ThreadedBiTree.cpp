
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <typeinfo>
using namespace std;
#define MAX_BITREE_SIZE 100
typedef char TElemType;
TElemType Nil = '#';

#include "ThrBiTree.h"

void Visit(TElemType e) {
    cout << e << ' ';
}

int main() {
    ThrBiTree BT;
    ThrBiNode *head;
    CreatThrBiTree(BT);
    InThreading_head(head,BT);
}