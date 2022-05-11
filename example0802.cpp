#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Members {
	char sNumber[8];
	char sName[20];
	float fSala;
};

typedef struct _Team {
	Members mem;			//数据区
	struct _Team* pNext;	//指针区
}Team;

Team* pHead = NULL;		//记录头节点
Team* pTail = NULL;		//记录尾节点

/*
	头插法：新数据在链表头部插入
*/
void AddToHead(Members mem)
{
	//malloc函数返回一个指针，指向已分配大小的内存。如果请求失败，则返回NULL。
	Team* pMem = (Team*)malloc(sizeof(Team));

	//空间开辟失败，程序退出
	if (!pMem)
		return;

	//链表为空时，记录尾节点
	if (!pHead)
		pTail = pMem;

	//链表数据准备
	pMem->mem = mem;
	pMem->pNext = pHead;

	//新数据节点从头部插入，头部指针更新
	pHead = pMem;

}

/*
	尾插法：新数据在链表尾部插入
*/
void AddToTail(Members mem)
{
	//malloc函数返回一个指针，指向已分配大小的内存。如果请求失败，则返回NULL。
	Team* pMem = (Team*)malloc(sizeof(Team));

	//空间开辟失败，程序退出
	if (!pMem)
		return;

	//链表为空时，记录头节点
	if (!pHead)
		pHead = pMem;

	//链表数据准备
	pMem->mem = mem;
	pMem->pNext = NULL;

	//插入的数据不为该链表的第一个数据时，数据节点从尾部插入
	if (pTail)
		pTail->pNext = pMem;

	//新数据节点从尾部插入，尾部指针更新
	pTail = pMem;

}

/*
	删除特定链表数据节点
*/
void Remove(const char* rmName)
{
	puts("==>链表节点数据删除");

	//定义指向头节点的临时指针变量，用以遍历该链表
	Team* pTmp = pHead;
	//遍历指针节点指针的上一个节点指针
	Team* pLast = NULL;
	int rmCount = 0;

	while (pTmp)
	{
		//strcmp函数的比较字符串相等时，返回0
		if (!(strcmp(rmName, pTmp->mem.sName)))
		{
			printf("该链表数据节点将被移除=>编号：%s,姓名：%s,工资：%0.2f\n", pTmp->mem.sNumber, pTmp->mem.sName, pTmp->mem.fSala);
			if (pLast)
				pLast->pNext = pTmp->pNext;	//删除数据节点
			else
				pHead = pTmp->pNext;	//删除数据节点为第一个时，删除/更新头节点

			//删除数据节点为尾节点时，尾节点更新，等于上一个数据节点
			if (!pTmp->pNext)
				pTail = pLast;

			rmCount++;
		}

		//更新上一个节点指针指向遍历节点指针
		pLast = pTmp;
		//更新遍历节点指针指向下一个节点
		pTmp = pTmp->pNext;
		
	}

	printf("链表移除了%d个数据节点。\n", rmCount);
}

/*
	打印链表全部内容
*/
void Out()
{
	puts("===链表节点数据打印");

	//定义指向头节点的临时指针变量，防止指针位置错乱
	Team* pTmp = pHead;
	int nCount = 1;

	while (pTmp)
	{
		printf("第%d位成员=>编号：%s,姓名：%s,工资：%0.2f\n", nCount, pTmp->mem.sNumber, pTmp->mem.sName, pTmp->mem.fSala);
		pTmp = pTmp->pNext;
		nCount++;
	}
}

void example0802()
{
	printf("=====example0802()=====\n");

	Members stu1 = { "10001", "赵一", 86954.81 };
	Members stu2 = { "10002", "李二", 39546.28 };
	Members stu3 = { "10003", "张三", 54216.25 };
	Members stu4 = { "10004", "李四", 89452.13 };
	Members stu5 = { "10005", "王五", 36854.96 };
	Members stu6 = { "10006", "钱六", 45812.21 };

	//例：先插头
	AddToHead(stu4);
	AddToHead(stu5);
	AddToTail(stu3);
	AddToTail(stu2);
	AddToHead(stu6);
	AddToTail(stu1);

	//例：先插尾
	AddToTail(stu4);
	AddToTail(stu5);
	AddToHead(stu3);
	AddToHead(stu2);
	AddToTail(stu6);
	AddToHead(stu1);

	Out();

	Remove("张三");
	Out();

	Remove("钱六");
	Out();

	Remove("赵一");
	Out();

	AddToHead(stu1);
	AddToTail(stu6);
	Out();
}