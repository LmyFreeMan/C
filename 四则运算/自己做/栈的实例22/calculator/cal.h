#pragma once
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
typedef  struct
{
	int *base;
	int *top;
	int stacksize;
}Stack;
void InitStack(Stack &s);
void PushStack(Stack &s, int e);
int  PopStack(Stack &s, int &e);
int Precede(Stack, int c);
int Operate(int a, int b, int c);
int GetTop(Stack s, int &e);