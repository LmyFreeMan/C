#include "Elemtype.h"
/*------------------------------------------------------------
// ջ�ṹ�Ķ���
------------------------------------------------------------*/
typedef struct
{
	ElemType *base;				// ջ��ַ
	ElemType *top;				// ջ��
	int stacksize;				// ջ�洢�ռ�ĳߴ�
} SqStack;

/*------------------------------------------------------------
// ջ�Ļ�������
------------------------------------------------------------*/

bool InitStack(SqStack &S);
/*void DestroyStack(SqStack &S);

int  StackLength(SqStack S);*/
ElemType GetTop(SqStack S);
bool Push(SqStack &S, ElemType e);
bool Pop(SqStack &S,ElemType &e);
bool StackEmpty(SqStack S);