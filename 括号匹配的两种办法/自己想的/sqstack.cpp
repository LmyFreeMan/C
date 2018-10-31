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
	  s.elemlength=0;
}
bool stackempty(sqstack s)
{
	if(s.elemlength==0) return  true;
	else                return false;
}
int stacklength(sqstack s)
{
	return s.elemlength;
}
// ≤Â»Î–¬µƒ‘™Àÿ◊˜Œ™’ª∂•‘™Àÿ
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
	s.elemlength++;
}
int  pop(sqstack &s,int &e)
{
	if(s.top=s.base)  return 0; 
      e=*--s.top;     
	 return e;
}
void  stacktraverse(sqstack s)
{
   int *p;
  p=s.base;
   while(p!=s.top)
   {
	   printf("%c",*p);
	  p++;
   }
} 
void index(sqstack &s)
{
	int *q=s.base;
	int *a;
	int i;
   if(s.elemlength%2==1) 
   {
	   printf("∆•≈‰ ß∞‹");
	   exit(0);
   }
   else
   {
	  while(q<=s.top)
	  {
		  if(*q=='('||*q=='[')
		  {
			  a=q;
		  }
		   q++;
	  }
	   if(a>=s.top)
		  {
                 printf("∆•≈‰ ß∞‹");
	               exit(0);
		  }
	   else
	   {
		   while(a>=s.base)
		   {
		     for(i=0;i<=s.elemlength;i++)
			 {
				 if((*a='('&&a[i]==')')||(*a='['&&a[i]==']'))
				 {
					 *a=0;
					 a[i]=0;
					 a--;
				 }
			 }
		   }
		  if(i>s.elemlength)
		   {
                        printf("∆•≈‰ ß∞‹");
	                      exit(0);
		   }
	   }

   }
          printf("∆•≈‰≥…π¶");

}
void destroystack(sqstack &s)
{
	free(&s);
}
