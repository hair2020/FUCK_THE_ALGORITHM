1.传值和返回值为引用 效率更高

2.Type char detail：http://c.biancheng.net/view/1323.html

3.
in xx.cpp file code:
    typedef int ElemType
    #include "xx.h"
write like this order, xx.h can recognize ElemType

4.
./6_Tree/ThreadedBiTree.cpp
    ThrBiTree BT;
    ThrBiNode *T;
    ThrBiNode TT;
    cout << typeid(BT).name() << ' ' << sizeof(BT) << '\n';
    cout << typeid(T).name() << ' ' << sizeof(T) << '\n';
    cout << typeid(*T).name() << ' ' << sizeof(*T) << '\n';
    cout << typeid(TT).name() << ' ' << sizeof(TT);

    output:
        P14ThreadedBiNode 8
        P14ThreadedBiNode 8
        14ThreadedBiNode 32
        14ThreadedBiNode 32