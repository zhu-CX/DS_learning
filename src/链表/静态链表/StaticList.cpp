#include"StaticList.h"

//申请静态链表结点
int Malloc_SL(StaticList &space)
{
	int i = space[1].cur;
	//如果备用区中还有可用空间那么就进行分配（更改备用区头指针的指向）
	if(space[1].cur != 0)
		space[1].cur = space[i].cur;
	return i;
}
//回收空间
void Free_SL(StaticList &space, int k)
{
	//将要回收的空间重新加入到备用空间
	space[k].cur = space[1].cur;
	space[1].cur = k;
}
//初始化
void InitSList(StaticList &space)
{
	//初始化备用空间pool(即下标1~MAX_SIZE-1)，其中下标为1的空间是备用空间的头结点，用于指向可使用的备用空间
	for(int i=1; i<MAX_SIZE-1; ++i) 
	{
		//备用区每个空间的游标指向下一个空间
		space[i].cur = i+1; 
	}
	//备用区的最后一个空间，后无可以空间，游标为0
	space[MAX_SIZE-1].cur = 0;
    //初始化时为空的静态链表，无数据结点，头结点的游标为-1
	space[0].cur = -1;  
}

//静态链表的头插
void Insert(StaticList &space, ElemType x)
{
	int i = Malloc_SL(space);//申请空间
	if(i == 0)//如果为零表示申请空间失败
	{
		printf("申请节点空间失败.\n");
		return;
	}
	
	space[i].data = x;
	//如果之前静态链表中无数据结点，需要更改头结点的指向
	if(space[0].cur == -1)
	{
		space[i].cur = -1;
		//space[0].cur = i;
	}
	else //如果之前已经有数据结点那么直接头插
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
}
//显示静态链表中的数据
void ShowSList(StaticList &space)
{
	int i = space[0].cur;//从第一个数据结点开始搜索
	while(i != -1)//将所有的数据结点打印
	{
		printf("%c-->",space[i].data);
		i = space[i].cur; // p = p->next;
	}
	printf("Nul.\n");
}
//静态链表的头删
void Delete(StaticList &space)
{
	//删除结点
	int i = space[0].cur;
	space[0].cur = space[i].cur;
	//释放删除结点的空间
	Free_SL(space,i);
}
