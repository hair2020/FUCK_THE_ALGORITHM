typedef  int ElemType;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 
# include "DoubleLinkList.h"

 int main()
     {int a,e;
      DuLinkList head,p,q;
      p=q=head=(DuLNode*)malloc(sizeof(DuLNode));
      scanf("%d",&a);
      while(a!=0)
       {p=(DuLNode*)malloc(sizeof(DuLNode));
        p->data=a;
        p->prior=q;
        q->next=p;
        q=p;
        scanf("%d",&a);}
        q->next=NULL;

        printf("插入之前的双向链表是:");
        p=head->next;
        while(p!=NULL)
        {printf("%3d,",p->data);
         p=p->next;}
         printf("\n");
        if(ListInsert_DuL(head,5,7))
		{
			printf("插入成功\n");
           printf("插入之后的双向链表是:");
         p=head->next;
        while(p!=NULL)
        {printf("%3d,",p->data);
         p=p->next;}
         printf("\n");
		}
        else printf("插入失败\n");
        
        if(ListDelete_DuL(head,5,e))
		{
			printf("删除成功\n");
			printf("被删除的元素是：%d\n",e); 
			printf("删除之后的双向链表是:");
		 p=head->next;
        while(p!=NULL)
        {printf("%3d,",p->data);
         p=p->next;}
          printf("\n");
		}
        else printf("删除失败\n");
  }
        