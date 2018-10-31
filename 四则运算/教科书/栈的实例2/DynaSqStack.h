#include "Elemtype.h"
/*------------------------------------------------------------
// 栈结构的定义
------------------------------------------------------------*/
typedef struct
{
	ElemType *base;				// 栈基址
	ElemType *top;				// 栈顶
	int stacksize;				// 栈存储空间的尺寸
} SqStack;

/*------------------------------------------------------------
// 栈的基本操作
------------------------------------------------------------*/

bool InitStack(SqStack &S);
/*void DestroyStack(SqStack &S);

int  StackLength(SqStack S);*/
ElemType GetTop(SqStack S);
bool Push(SqStack &S, ElemType e);
bool Pop(SqStack &S,ElemType &e);
bool StackEmpty(SqStack S);