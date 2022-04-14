#include<stdio.h>

/*
List:
InitList(*L) : 初始化操作，建立一个空的线性表L.
ListEmpty(L) : 若线性表为空，返回true,否则返回false.
ClearList(*L) : 将线性表清空.
GetElem(L,i,*e) : 将线性表L中的第i个位置元素值返回给e.
LocateElem(L,e) : 在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中的序号表示成功；否则返回0表示失败.
ListInsert(*L,i,e) : 在线性表L中的第i个位置插入新元素e.
ListDelete(*L,i,*e) : 删除线性表L中第i个位置元素，并用e返回其值.
ListLength(L) : 返回线性表L的元素个数.
*/

typedef int ElemType;
typedef int Status;

#define MAXSIZE 20  //存储空间初始分配量

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//初始化，建立一个空线性表
void InitList(SqList *L)
{
    L->length=0;
}

//将线性表L中的第i个位置元素值返回给e.
Status GetElem(SqList L,int i,ElemType *e)
{
    if (L.length==0 || i<1 || i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

//在线性表L中的第i个位置插入新元素e.
Status ListInsert(SqList *L,int i, ElemType e)
{
    int k;
    if (L->length==MAXSIZE)     //顺序线性表已满
        return ERROR;
    if (i<1 || i>L->length+1)   //当i不在范围内时
        return ERROR;
    if (i<=L->length)       //若插入数据位置不在表尾
    {
        for (k=L->length-1;k>=i-1;k--)      //将要插入位置后的数据向后移动一位
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;     //将新元素插入
    L->length++;
    return OK;
}

//删除线性表L中第i个位置元素，并用e返回其值.
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if (L->length==0)       //线性表为空
        return ERROR;
    if (i<1 || i>L->length)     //删除位置不正确
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)        //删除的不是最后位置
    {
        for(k=i;k<L->length;k++)        //删除位置后继元素前移
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

//在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中的序号表示成功；否则返回0表示失败.
Status LocateElem(SqList *L,ElemType e)
{
    int i=1;
    while(i<=L->length && L->data[i]!=e)
        i++;
    if(i>L->length)
        return FALSE;       //查找失败
    else
        return i;       //返回x的存储位置
}

//顺序表合并且按序排列
void merge(SqList *A,SqList *B,SqList *C)
{
    int i,j,k;
    i=1;j=1;k=1;
    while(i<=A->length && j<=B->length){
        if (A->data[i]<=B->data[j])
            C->data[k++]=A->data[i++];
        else
            C->data[k++]=B->data[j++];
    }
    while(i<=A->length)
        C->data[k++]=A->data[i++];
    while(j<=B->length)
        C->data[k++]=B->data[j++];
    C->length=A->length+B->length;
}