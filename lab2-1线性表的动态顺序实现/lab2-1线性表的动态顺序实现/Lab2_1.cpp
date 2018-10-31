#include <stdio.h>
#include "SqList.h"
# include<windows.h>
int main()
{
	printf("this is ok!");
    SqList l;
	ElemType e;
    InitList(l);
	//DestroyList(&l);
	if(ListEmpty(l))
		printf("动态顺序表为空\n");
	else
		printf("动态顺序表不空了\n");
	int i=0;
	int a=0;
	while(i<7){
		printf("请输入第%d个元素\n",i+1);
		scanf("%d",&a);
        if(ListInsert(l,i+1,a))
			printf("插入成功！\n");
		i++;
	}
	for(i=0;i<l.length ;i++)
		printf("%d,",GetElem(l,i));
	printf("\n");
	ListDelete(l,3,e);
	ListInsert(l, 3, 5);
    for(i=0;i<l.length ;i++)
		printf("%d,",GetElem(l,i));
	system("pause");
	return 0;
};