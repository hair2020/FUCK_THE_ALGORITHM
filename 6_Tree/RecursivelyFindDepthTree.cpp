#include <iostream>
using namespace std;

int test(int f){
    int f0=0,f1=0;
    if (f < 1) return 0;
    f0 = test(f-1);
    f1 = test(f-1);
    return f0>f1 ? f0+1:f1+1;
}
// this program's answer is equivalent to a complete binary tree's depth
// use it to understand recursive procedures
int main() {
    int f = 3;
    int ans = test(3);
    cout <<  ans;
    return 0;
}