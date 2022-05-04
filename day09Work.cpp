#include <stdio.h>
#include <stdlib.h>

void work0901()
{
	printf("↓↓↓↓↓day09Work.cpp ==> work0901()↓↓↓↓↓\n");

	//int a[10] = { [5] = 1,2,3,4,5 };

	int ds[10] = { 1,2,3,4,5,6,7,8,0,9 };
	int* p;
	p = ds;

	//这里判断条件不能使用p(无法结束)和*p(int类型的0表示结尾,到0结束)
	while (p - ds < _countof(ds))
		printf("%d ", *p++);
}

void day09Work()
{
	void work0901();
	work0901();
}