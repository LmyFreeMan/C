#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
#include "SqList.h"
#include <stdio.h>
#define LIST_INIT_SIZE 10// ���ʼ�������󳤶�

#define LISTINCREMENT 10	// �����ڴ������

/*------------------------------------------------------------
����Ŀ�ģ�	��ʼ��˳���
��ʼ������	��
���������	����һ���յ����Ա�
����������
		SqList *L	����ʼ�������Ա�
����ֵ��
		bool		�����Ƿ�ɹ�
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
����Ŀ�ģ�	����˳���
��ʼ������	���Ա�L�Ѵ���
���������	�������Ա�L
����������
		SqList *L	�����ٵ����Ա�
����ֵ��
		��
------------------------------------------------------------*/
void DestroyList(SqList &L)
{
	if(L.elem){
		free(L.elem);
		L.elem=NULL;
	}
}

/*------------------------------------------------------------
����Ŀ�ģ�	�ж�˳����Ƿ�Ϊ��
��ʼ������	���Ա�L�Ѵ���
���������	��LΪ�ձ��򷵻�true�����򷵻�false
����������
		SqList L	���жϵ����Ա�
����ֵ��
		bool		�Ƿ�Ϊ��
------------------------------------------------------------*/
bool ListEmpty(SqList L)
{

	if(L.length==0) 
		 return true;
	 else 
		 return false;
    
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�˳���ĳ���
��ʼ������	���Ա�L�Ѵ���
���������	����L������Ԫ�صĸ���
����������
		SqList L	���Ա�L
����ֵ��
		int			����Ԫ�صĸ���
------------------------------------------------------------*/
int ListLength(SqList L)
{
	return L.length;
}
/*------------------------------------------------------------
����Ŀ�ģ�	��˳����ָ��λ�ò����㣬����λ��i��ʾ�ڵ�i��
			Ԫ��֮ǰ����
��ʼ������	���Ա�L�Ѵ��ڣ�1<=i<=ListLength(L) + 1
���������	��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
����������
		SqList *L	���Ա�L
		int i		����λ��
		ElemType e	�����������Ԫ��
����ֵ��
		bool		�����Ƿ�ɹ�
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