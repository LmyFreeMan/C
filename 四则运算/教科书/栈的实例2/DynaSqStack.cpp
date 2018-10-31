#include <malloc.h>
#include "DynaSqStack.h"
#include <stdio.h>
const int STACK_INIT_SIZE = 100;	// ��ʼ����ĳ���
const int STACKINCREMENT  = 10;		// �����ڴ������

/*------------------------------------------------------------
����Ŀ�ģ�	��ʼ��ջ
��ʼ������	��
���������	����һ���յ�ջ
����������
		SqStack *S	����ʼ����ջ
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool InitStack(SqStack &S)
{
	S.base=S.top=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base)
		return false;
	S.stacksize=STACK_INIT_SIZE;
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�ж�ջ�Ƿ�Ϊ��
��ʼ������	ջS�Ѵ���
���������	��SΪ��ջ���򷵻�true�����򷵻�false
����������
		SqStack S	���жϵ�ջ
����ֵ��
		bool		�Ƿ�Ϊ��
------------------------------------------------------------*/
bool StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�ջ��Ԫ��
��ʼ������	ջS�Ѵ���
���������	��e����ջ��Ԫ��
����������
		SqStack S	ջS
		ElemType *e	ջ��Ԫ�ص�ֵ
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
ElemType GetTop(SqStack S)
{
	ElemType e;
	if(S.base!=S.top){
        e=*(S.top-1);
		return e;
	}
	else
		return 0;
}

/*------------------------------------------------------------
����Ŀ�ģ�	ѹջ��������Ԫ��eΪ�µ�ջ��Ԫ��
��ʼ������	ջS�Ѵ���
���������	��������Ԫ��e��Ϊ�µ�ջ��
����������
		SqStack *S	ջS
		ElemType e	�����������Ԫ��
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool Push(SqStack &S, ElemType e)
{
	if(S.top-S.base<S.stacksize){
		*(S.top)=e;
	    S.top++;
		return true;
	}
	else
		return false;
}

/*------------------------------------------------------------
����Ŀ�ģ�	��ջ����ɾ��ջ��Ԫ��
��ʼ������	ջS�Ѵ����ҷǿ�
���������	ɾ��S��ջ��Ԫ�أ�����e������ֵ
����������
		SqStack *S	ջS
		ElemType *e	��ɾ��������Ԫ��ֵ$
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool Pop(SqStack &S,ElemType &e)
{
	
	if(S.base!=S.top)		e=*--S.top;
	return true;
		
	
}