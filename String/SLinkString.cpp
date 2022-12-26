#include <iostream>
#include"SLinkString.h"
int main() {
	SLinkString S1 = NULL, S2 = NULL, S3 = NULL, S4 = NULL;
	int x;
    char a[] = "child";
    char b[] = "children";
    char c[] = "chinese chair technology ";
    char d[] = "";
	StrAssign_L(S1, a);
	StrAssign_L(S2, b);
	StrAssign_L(S3, c);
	StrAssign_L(S4, d);
	StrTraverse_L(S1);
	
	StrCopy_L(S4, S1);
	cout << "串S4被复制后的值为：";
	StrTraverse_L(S4);
	if (StrCompare_L(S1, S2)>0) cout << "串S1>串S2" << endl;
	else if (StrCompare_L(S1, S2) == 0)  cout << "串S1=串S2" << endl;
	else if (StrCompare_L(S1, S2)<0)  cout << "串S1<串S2" << endl;
	if (StrConcat_L(S3, S4)) {
		cout << "串S3与S4连接成功\n即" << endl;
		StrTraverse_L(S3);
	}
	else {
		cout << "连接失败" << endl;
	}
    char e[] = "ch";
    char f[] = "abcd";
	StrAssign_L(S1, e);
	StrAssign_L(S2, f);
	return 0;
}
