#include "ElemType.h"
typedef struct
{
	ElemType *elem;				// 存储空间的基址
	int length;					// 顺序表中结点元素的个数
	int listsize;				// 顺序表的存储空间大小
} SqList;

/*------------------------------------------------------------
// 顺序表的基本操作
------------------------------------------------------------*/

bool InitList(SqList &L);
void DestroyList(SqList &L);
bool ListEmpty(SqList L);
int  ListLength(SqList L);
bool ListInsert(SqList &L, int i, ElemType e);
ElemType GetElem(SqList L, int i);
bool ListDelete(SqList &L, int i, ElemType &e);

/*int  LocateElem(SqList L, ElemType e, int (*fp)(ElemType, ElemType));
bool PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
bool NextElem(SqList L, ElemType cur_e, ElemType *nxt_e);
void ListTraverse(SqList L, void (*fp)(ElemType));
void ClearList(SqList *L);

*/
