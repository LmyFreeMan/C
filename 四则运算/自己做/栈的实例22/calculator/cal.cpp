# include<stdio.h>
# include"cal.h"
# include<stdlib.h>
void InitStack(Stack &s)
{
	s.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	s.top = s.base;
	if (!s.base)  exit(0);
	s.stacksize = STACK_INIT_SIZE;
}
void PushStack(Stack &s, int e)
{                                                     
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (int *)realloc(s.base, (s.stacksize + STACKINCREMENT)*sizeof(int));
		if (!s.base) exit(0);
		s.top =s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top = e;
	s.top++;
}
int  PopStack(Stack &s, int &e)
{
	if (s.top == s.base) return 0;
	e = *--s.top;
	return e;
}
int Precede(Stack s, int c)
{
	char ch=0;
	int e;
	//printf("%c", GetTop(s, e));
	if (GetTop(s,e) == '+')
	{
		if (c == '+') ch = '>';
		if (c == '-') ch = '>';
		if (c == '*') ch = '<';
		if (c == '/') ch = '<';
		if (c == '(') ch = '<';
		if (c == ')') ch = '>';
		if (c == '#') ch = '>';
		if (c == '=') ch = '>';
	}
	if (GetTop(s, e) == '-')
	{
		if (c == '+') ch = '>';
		if (c == '-') ch = '>';
		if (c == '*') ch = '<';
		if (c == '/') ch = '<';
		if (c == '(') ch = '<';
		if (c == ')') ch = '>';
		if (c == '#') ch = '>';
		if (c == '=') ch = '>';
	}
	if (GetTop(s, e) == '*')
	{
		if (c == '+') ch = '>';
		if (c == '-') ch = '>';
		if (c == '*') ch = '>';
		if (c == '/') ch = '>';
		if (c == '(') ch = '<';
		if (c == ')') ch = '>';
		if (c == '#') ch = '>';
		if (c == '=') ch = '>';
	}
	if (GetTop(s, e) == '/')
	{
		if (c == '+') ch = '>';
		if (c == '-') ch = '>';
		if (c == '*') ch = '>';
		if (c == '/') ch = '>';
		if (c == '(') ch = '<';
		if (c == ')') ch = '>';
		if (c == '#') ch = '>';
		if (c == '=') ch = '>';
	}
	if (GetTop(s, e) == '(')
	{
		if (c == '+') ch = '<';
		if (c == '-') ch = '<';
		if (c == '*') ch = '<';
		if (c == '/') ch = '<';
		if (c == ')') ch = '=';
	}
	if (GetTop(s, e) == ')')
	{
		if (c == '+') ch = '>';
		if (c == '-') ch = '>';
		if (c == '*') ch = '>';
		if (c == '/') ch = '>';
		if (c == '(') ch = '=';
	}
	if (GetTop(s, e) == '#')
	{
		if (c == '+') ch = '<';
		if (c == '-') ch = '<';
		if (c == '*') ch = '<';
		if (c == '/') ch = '<';
		if (c == '(') ch = '<';
		if (c == '#') ch = '=';
	}
	return ch;
}
	int Operate(int a, int b, int c)
	{
		int result = 0;
		switch (c)
		{
		   case '+': result = a + b;break;
		   case '-': result = a - b;break;
		   case '*': result = a* b;break;
		   case '/': result = a/ b;break;
		}
		  return result;
	}
	int GetTop(Stack s, int &e)
	{
		if (s.base == s.top) exit(0);
		e = *(s.top - 1);
		return e;
	}
