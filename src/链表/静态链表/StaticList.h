#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#include<stdio.h>

#define MAX_SIZE 20
#define ElemType char

typedef struct ListNode
{
	ElemType data;
	int      cur;   //静态链表中的游标
}ListNode;

//静态链表实际上就是一个结构体数组
typedef ListNode StaticList[MAX_SIZE]; 

int Malloc_SL(StaticList &space);
void Free_SL(StaticList &sapce,int k);

void InitSList(StaticList &space);
void Insert(StaticList &space, ElemType x);
void Delete(StaticList &space);
void ShowSList(StaticList &space);

#endif //__STATICLIST_H__
