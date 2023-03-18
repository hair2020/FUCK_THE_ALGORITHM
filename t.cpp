#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

int test(int a,int b){

    return a>b ? a+1:b+1;
}
int main() {
    int ans = test(5,3);
    cout <<  ans;
    return 0;
}