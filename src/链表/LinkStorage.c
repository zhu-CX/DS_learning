#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node,*LinkList;

//单链表的初始化
LinkList ListInit(){
    LinkList head;
    head=(LinkList)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}

//头插法，建立带头结点的单链表，随机产生n个元素的值
void CreateListHead(LinkList *L,int n){
    LinkList p;
    int i;
    srand(time(0));     //初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;        //先建立一个带头结点的单链表
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;       //随机生成100以内的数字
        p->next=(*L)->next;
        (*L)->next=p;       //插入到表头.    
    }
}

//尾插法，带头结点，随机产生n个值
void CreateListTail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));     //初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));      //为整个线性表
    r=*L;       //r指向尾部的结点
    for(i=0;i<n;i++){
        p=(Node*)malloc(sizeof(Node));      //生成新结点
        p->data=rand()%100+1;       //随机生成100以内的数字
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

//获取L中第i个数据
Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;     //声明一结点p,让p指向链表L的第一个结点
    p=L->next;
    j=1;        //j为计数器
    while(p && j<i){
        p=p->next;
        ++j;
    }       //p不为空或j!=i
    if(!p || j>i)
        return ERROR;       //第i个元素不存在
    *e=p->data;
    return OK;
}

//链表的插入算法
Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i){
        p=p->next;
        ++j;
    }       //寻找第i个结点
    if (!p || j>i)
        return ERROR;       //第i个元素不存在
    s=(LinkList)malloc(sizeof(Node));       //生成新结点
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

//单链表的第i个元素的删除
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p=*L;
    j=1;
    while(p->next && j<i){
        p=p->next;
        ++j;
    }       //遍历寻找第i个元素
    if(!(p->next) || j>i)
        return ERROR;       //第i个元素不存在
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return OK;
}

//单链表的整表删除,重置为空表
Status ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->next;       //p指向第一个结点
    while(p){           //没到表尾
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;        //头结点指针域为空
    return OK;
}
