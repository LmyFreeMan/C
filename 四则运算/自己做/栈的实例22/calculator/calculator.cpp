# include<stdio.h>
# include"cal.h"
# include<stdlib.h>
void main()
{
	int a,b,c,e,r,flag,d;
	a=b=r = 0;
	Stack OPTR;//寄存运算符
	Stack OPND;//寄存操作数或者运算结果
	InitStack(OPTR);
	PushStack(OPTR,'#');
	InitStack(OPND);
	c = getchar();
	while (c!='='||GetTop(OPTR,e)!='#')
	{
		if (c>='0'&&c<='9')
		{
			PushStack(OPND, c-'0');
			c = getchar();
		}
		else
		{
			switch (Precede(OPTR,c))
			{
			case'<':PushStack(OPTR, c);c = getchar(); break;
			case'>': r = PopStack(OPTR, d);PopStack(OPND, b);PopStack(OPND, a);PushStack(OPND, Operate(a, b, r));break;
			case'=':r = PopStack(OPTR, d);c=getchar();
			}
		}
	}
	    printf("%d", GetTop(OPND, e));
}