#include <malloc.h>
#include "DynaSqStack.h"
#include <stdio.h>
const int STACK_INIT_SIZE = 100;	// 初始分配的长度
const int STACKINCREMENT  = 10;		// 分配内存的增量

/*------------------------------------------------------------
操作目的：	初始化栈
初始条件：	无
操作结果：	构造一个空的栈
函数参数：
		SqStack *S	待初始化的栈
返回值：
		bool		操作是否成功
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
操作目的：	判断栈是否为空
初始条件：	栈S已存在
操作结果：	若S为空栈，则返回true，否则返回false
函数参数：
		SqStack S	待判断的栈
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

/*------------------------------------------------------------
操作目的：	得到栈顶元素
初始条件：	栈S已存在
操作结果：	用e返回栈顶元素
函数参数：
		SqStack S	栈S
		ElemType *e	栈顶元素的值
返回值：
		bool		操作是否成功
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
操作目的：	压栈——插入元素e为新的栈顶元素
初始条件：	栈S已存在
操作结果：	插入数据元素e作为新的栈顶
函数参数：
		SqStack *S	栈S
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
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
操作目的：	弹栈——删除栈顶元素
初始条件：	栈S已存在且非空
操作结果：	删除S的栈顶元素，并用e返回其值
函数参数：
		SqStack *S	栈S
		ElemType *e	被删除的数据元素值$
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool Pop(SqStack &S,ElemType &e)
{
	
	if(S.base!=S.top)		e=*--S.top;
	return true;
		
	
}