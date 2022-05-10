#include <stdio.h>
#include <string.h>

/*
==>
	利用指针修改结构体内的单个数据
		指针法修改数据,.的优先级比*高,所以需要给*加上(),以提升*的优先级.
			((*p).nNumb = 1003;)
		指针符号法修改数据
			p->fSala = 8887.77f;
	修改结构体内的数组数据时,使用strcpy_s函数
		strcpy_s(w1.sName, w2.sName);
<==
*/

typedef struct _SWork
{
	int nNumb;			//工号
	char sName[20];		//姓名
	float fSala;			//工资
}SWork;

void example0704()
{
	printf("=====example0704()=====\n");

	_SWork w1 = { 1001, "张三", 9898.89 };
	SWork w2 = { 1002, "李四", 9999.77 };
	SWork* p;
	
	p = &w1;
	//p指向的对象内的数据为:1001,张三,9898.889648 .的优先级比*高,所以需要给*加上(),以提升*的优先级.
	printf("p指向的对象内的数据为:%d,%s,%f\n", (*p).nNumb, (*p).sName, (*p).fSala);

	//指针法修改数据
	(*p).nNumb = 1003;
	//w1象内的数据为：1003,张三,9898.889648 
	printf("w1象内的数据为：%d,%s,%2f\n", w1.nNumb, w1.sName, w1.fSala);

	//指针符号法修改数据
	p->fSala = 8887.77f;
	//p指向的对象内的数据为:1003,张三,8887.769531
	printf("p指向的对象内的数据为:%d,%s,%f\n", p->nNumb, p->sName, p->fSala);

	//strcpy函数法修改数据
	strcpy_s(w1.sName, w2.sName);
	//w1象内的数据为：1003,李四,8887.769531
	printf("w1象内的数据为：%d,%s,%2f\n", w1.nNumb, w1.sName, w1.fSala);
}