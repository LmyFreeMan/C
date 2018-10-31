# include<stdio.h>
# include<stdlib.h>
# include"sqstack.h"
void main()
{
	int elem,e;
	int a;
	sqstack l;
	initstack(l);
	printf("请输入'('或者'[',按回车键结束\n");
	while(1)
	{
	  e=getchar();
	  if(e=='#')
		break;
	 push(l,e);
	}
    printf("请输入')'或者']',按#号键结束'\n");
	getchar();
	while(1)
	{ 
      elem=getchar();
      switch(elem)
	  {
	  case ')':if (pop(l,a) == '(') break;
			   else { printf("匹配失败");exit(0); }
	  case ']':if(pop(l,a) == '[') break;
			   else {
				   printf("匹配失败");exit(0);
			   }
	  case '#':break;
	  }
	  break;
	}
	printf("匹配成功");
	while (1)
	{
		getchar();
	}
}
