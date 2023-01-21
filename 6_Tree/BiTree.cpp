#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

#include "BiTree.h"
int main() {
    BiTree BT;
    CreateBiTree(BT);
    cout << BiTreeDepth(BT);
    return 0;
}