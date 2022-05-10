#include <stdio.h>
#include <stdlib.h>

struct Members {
	char sNumber[8];
	char sName[20];
	float fSala;
};

typedef struct _Team {
	Members mem;			//数据区
	struct _Team* pNext;		//指针区
}Team;

//全局链表
Team* gClass = NULL;
Team* pHead = NULL;	//记录头节点
Team* pTail = NULL;	//记录尾节点

/*
	头插法：新数据在链表头部插入
*/
void AddToHead(Members stu)
{
	//malloc函数返回一个指针，指向已分配大小的内存。如果请求失败，则返回NULL。
	Team* pMem = (Team*)malloc(sizeof(Team));

	//空间开辟失败，程序退出
	if (!pMem)
		return;

	//链表为空时，记录尾节点
	if (!gClass)
		pTail = pMem;

	//链表数据插入
	pMem->mem = stu;
	pMem->pNext = gClass;
	gClass = pMem;

	//更新头节点
	pHead = pMem;
}

/*
	尾插法：新数据在链表尾部插入
*/
void AddToTail(Members stu)
{
	//malloc函数返回一个指针，指向已分配大小的内存。如果请求失败，则返回NULL。
	Team* pMem = (Team*)malloc(sizeof(Team));

	//空间开辟失败，程序退出
	if (!pMem)
		return;

	//链表为空时，记录头节点
	if (!gClass)
		pHead = pMem;

	//链表数据插入
	pMem->mem = stu;
	pMem->pNext = NULL;

	//判断插入的数据是否为该链表的第一个数据
	if (gClass)
		pTail->pNext = pMem;	//插入的数据不为该链表的第一个数据
	else
		gClass = pMem;	//插入的数据为该链表的第一个数据

	//更新尾节点
	pTail = pMem;
}

void Out()
{
	Team* tmp = pHead;
	int nCount = 1;
	while (tmp)
	{
		printf("第%d位成员=>编号：%s,姓名：%s,工资：%0.2f\n", nCount, tmp->mem.sNumber, tmp->mem.sName, tmp->mem.fSala);
		tmp = tmp->pNext;
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
	/*AddToTail(stu4);
	AddToTail(stu5);
	AddToHead(stu3);
	AddToHead(stu2);
	AddToTail(stu6);
	AddToHead(stu1);*/

	Out();
}