#include<stdio.h>

/*
==>
	指针做形参时:p无效,*p有效
		指针形参(p)交换不会改变实参
		指针形参值(*p)交换会改变实参值
<==
*/

/*
	形参值交换,实参没有交换
*/
void swap1(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

/*
	形参值交换,实参没有交换
*/
void swap2(int* p1, int* p2)
{
	int* t = p1;
	p1 = p2;
	p2 = t;
}

/*
	形参指向值交换,实参交换
*/
void swap3(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}

void example0701()
{
	printf("=====example0701()=====\n");
	
	int x = -1, y = 0;
	//交换前:x=-1,*x=000000D760EFF884,y=0,*y=000000D760EFF8A4
	printf("交换前:x=%d,*x=%p,y=%d,*y=%p\n", x, &x, y, &y);

	swap1(x, y);
	//第一次交换后:x=-1,*x=000000D760EFF884,y=0,*y=000000D760EFF8A4
	printf("第一次交换后:x=%d,*x=%p,y=%d,*y=%p\n", x, &x, y, &y);

	swap2(&x, &y);
	//第二次交换后:x=-1,*x=000000D760EFF884,y=0,*y=000000D760EFF8A4
	printf("第二次交换后:x=%d,*x=%p,y=%d,*y=%p\n", x, &x, y, &y);

	swap3(&x, &y);
	//第三次交换后:x=0,*x=000000D760EFF884,y=-1,*y=000000D760EFF8A4
	printf("第三次交换后:x=%d,*x=%p,y=%d,*y=%p\n", x, &x, y, &y);
	
}