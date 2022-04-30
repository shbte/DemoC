#include <stdio.h>
#include <stdlib.h>

/*
==>
	结构体指针做形参时:p修改无效,*p(p[i])修改有效
<==
*/

typedef struct _SWork
{
	int nNumb;			//工号
	char sName[20];		//姓名
	float fSala;			//工资
}SWork;

//结构体做参数
void intSWork(SWork w)
{
	SWork w2 = { 1001, "张三", 700.78 };
	w = w2;

	//intSWork ==> 1001,张三,700.780029
	printf("intSWork ==> %d,%s,%f\n", w2.nNumb, w2.sName, w2.fSala);
}
//结构体做参数
void outSWork(SWork w)
{
	//outSWork ==> 0,,0.000000
	printf("outSWork ==> %d,%s,%f\n", w.nNumb, w.sName, w.fSala);
}

//结构体指针做参数
void intSWorkPointer1(SWork* wp)
{
	SWork w2 = { 1002, "李四", 990.98 };
	*wp = w2;

	//intSWorkPointer1 ==> 1002,李四,990.979980 修改有效
	printf("intSWorkPointer1 ==> %d,%s,%f\n", (*wp).nNumb, (*wp).sName, (*wp).fSala);
}
void intSWorkPointer2(SWork* wp)
{
	SWork w2 = { 1003, "王五", 860.48 };
	wp = &w2;

	//intSWorkPointer2 ==> 1003,王五,860.479980 修改无效
	printf("intSWorkPointer2 ==> %d,%s,%f\n", wp->nNumb, wp->sName, wp->fSala);
}
void outSWorkPointer(SWork* wp)
{
	//outSWorkPointer ==> 1002,李四,990.979980
	printf("outSWorkPointer ==> %d,%s,%f\n", (*wp).nNumb, (*wp).sName, (*wp).fSala);
	//outSWorkPointer ==> 1002,李四,990.979980
	printf("outSWorkPointer ==> %d,%s,%f\n", wp->nNumb, wp->sName, wp->fSala);
}

//结构体数组
void intSWorkArray1(SWork* p, int nCount)
{
	int i = 0;
	SWork w;
	while (i++ < nCount)
	{
		w = { 1004 + i, "赵六", 310.54 };
		*p = w;

		//intSWorkArray1 ==> 1004,赵六,310.540009 修改有效
		printf("intSWorkArray1 ==> %d,%s,%f\n", p[0].nNumb, (*p).sName, p->fSala); //因为p++已经移位了,所以这里不用p[i]

		p++;
	}
}
void intSWorkArray2(SWork* p, int nCount)
{
	int i = 0;
	SWork w;
	while (i++ < nCount)
	{
		w = { 1005 + i, "孙七", 750.20 };
		p = p + i - 1; //移位,可用p++或++p代替
		p = &w;

		//intSWorkArray2 ==> 1005,孙七,750.200012 修改无效
		printf("intSWorkArray2 ==> %d,%s,%f\n", p[0].nNumb, (*p).sName, p->fSala);
	}
}
void intSWorkArray3(SWork* p, int nCount)
{
	int i = -1;
	SWork w;
	while (++i < nCount)
	{
		w = { 1006 + i, "钱八", 910.26 };
		p[i] = w;

		//intSWorkArray3 ==> 1006,钱八,910.260010 修改有效
		printf("intSWorkArray3 ==> %d,%s,%f\n", p[i].nNumb, p[i].sName, p[i].fSala);
	}
}
void outSWorkArray(SWork* p, int nCount)
{
	while (nCount--)
	{
		//outSWorkArray ==> 1004,赵六,310.540009 下标法打印
		//printf("outSWorkArray ==> %d,%s,%f\n", p[nCount].nNumb, p[nCount].sName, p[nCount].fSala);

		//outSWorkArray ==> 1006,钱八,910.260010 指针法打印
		//printf("outSWorkArray ==> %d,%s,%f\n", p[0].nNumb, (*p).sName, p->fSala);
		//p++;

		//outSWorkArray ==> 1006,钱八,910.260010 指针发打印 (4-nCount)代替了p++丶++p
		printf("outSWorkArray ==> %d,%s,%f\n", p[4 - nCount].nNumb, (*(p + 4 - nCount)).sName, (p + 4 - nCount)->fSala);
	}
}

void example0705()
{
	printf("=====example0705()=====\n");

	SWork w1 = { 0 };
	//main ==> 0,,0.000000
	printf("main ==> %d,%s,%f\n", w1.nNumb, w1.sName, w1.fSala);
	
	intSWork(w1);
	outSWork(w1);

	intSWorkPointer1(&w1);
	intSWorkPointer2(&w1);
	outSWorkPointer(&w1);

	SWork wa[5];

	//intSWorkArray1 ==> 1005,赵六,310.540009
	intSWorkArray1(wa, _countof(wa));
	//intSWorkArray2 ==> 1006,孙七,750.200012
	intSWorkArray2(wa, _countof(wa));
	//outSWorkArray ==> 1009,赵六,310.540009
	outSWorkArray(wa, _countof(wa));

	//intSWorkArray3 ==> 1006,钱八,910.260010
	intSWorkArray3(wa, _countof(wa));
	//outSWorkArray ==> 1010,钱八,910.260010
	outSWorkArray(wa, _countof(wa));

}