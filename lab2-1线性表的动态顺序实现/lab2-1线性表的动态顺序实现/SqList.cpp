#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
#include "SqList.h"
#include <stdio.h>
#define LIST_INIT_SIZE 10// 表初始分配的最大长度

#define LISTINCREMENT 10	// 分配内存的增量

/*------------------------------------------------------------
操作目的：	初始化顺序表
初始条件：	无
操作结果：	构造一个空的线性表
函数参数：
		SqList *L	待初始化的线性表
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitList(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		return false;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return true;
}

/*------------------------------------------------------------
操作目的：	销毁顺序表
初始条件：	线性表L已存在
操作结果：	销毁线性表L
函数参数：
		SqList *L	待销毁的线性表
返回值：
		无
------------------------------------------------------------*/
void DestroyList(SqList &L)
{
	if(L.elem){
		free(L.elem);
		L.elem=NULL;
	}
}

/*------------------------------------------------------------
操作目的：	判断顺序表是否为空
初始条件：	线性表L已存在
操作结果：	若L为空表，则返回true，否则返回false
函数参数：
		SqList L	待判断的线性表
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool ListEmpty(SqList L)
{

	if(L.length==0) 
		 return true;
	 else 
		 return false;
    
}

/*------------------------------------------------------------
操作目的：	得到顺序表的长度
初始条件：	线性表L已存在
操作结果：	返回L中数据元素的个数
函数参数：
		SqList L	线性表L
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int ListLength(SqList L)
{
	return L.length;
}
/*------------------------------------------------------------
操作目的：	在顺序表的指定位置插入结点，插入位置i表示在第i个
			元素之前插入
初始条件：	线性表L已存在，1<=i<=ListLength(L) + 1
操作结果：	在L中第i个位置之前插入新的数据元素e，L的长度加1
函数参数：
		SqList *L	线性表L
		int i		插入位置
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListInsert(SqList &L, int i, ElemType e)
{
	ElemType *newbase,*p,*q;
	if(i<1||i>L.length +1) return false;
	if(L.length >=L.listsize )
	{
		newbase=(ElemType*)realloc(L.elem ,(L.listsize +LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) return false;
		L.elem=newbase;
		L.listsize +=LISTINCREMENT;
	}
	q=&(L.elem [i-1]);
	for(p=&(L.elem [L.length -1]);p>=q;--p) 
		*(p+1)=*p;
	*q=e;
	++L.length ;
	return true;
}
ElemType  GetElem(SqList L, int i)
{
	if(i<0 ||i>L.length) return -1;
	return L.elem [i];
	
}
bool ListDelete(SqList &L, int i, ElemType &e)
{
	ElemType *p,*q;
	if ((i<1)||(i>L.length )) return false;
	p=&L.elem [i-1];
	e=*p;
	q=L.elem +L.length -1;
	for(++p;p<=q;++p) *(p-1)=*p;
	--L.length ;
	return true;
}