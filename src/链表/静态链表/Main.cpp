#include"StaticList.h"
#include"StaticList.cpp"

int main()
{
	StaticList SL;  //建立静态链表
	InitSList(SL);  //初始化静态链表

	for(int i=0; i<5; ++i)
	{
		Insert(SL,'A'+i);//头插
	}
	//显示静态链表的数据
	ShowSList(SL);	
	Delete(SL);//头删
	ShowSList(SL);
    return 0;
}
