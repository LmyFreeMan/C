# include<stdio.h>
# include<stdlib.h>
# include"sqstack.h"
# define STACK_INIT_SIZI 100
# define STACKINCREMENT  8
void initstack(sqstack &s)
{
      s.base=(int *)malloc(STACK_INIT_SIZI*sizeof(int));
	  if(!s.base)  exit(0);
	  s.top=s.base;
	  s.stacksize=STACK_INIT_SIZI;
}
// 插入新的元素作为栈顶元素
void push(sqstack &s,int &e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.base=(int *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(int));
		if(!s.base)  exit(0);
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top=e;
	  s.top++;
}
int pop(sqstack &s,int &e)
{
	if(s.top==s.base)
		exit(0);
      e=*--s.top;     
	  return e;
}
void destroystack(sqstack &s)
{
	free(&s);
}
