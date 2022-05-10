#include <stdio.h>

/*
==>
	数组也是一种指针,指向的是数组的首元素
	指针也能当成数组使用,指针可以使用下标访问数组元素
	数组名自身就是指向数组「第一个元素」的指针，因此指针法可以直接作用于数组名,数组名实际上是一个地址(不可用于++操作,因地址是不可修改的)
<==
*/
void example0601()
{
	printf("=====example0601()=====\n");

	double d[5] = { 12,-4,12.32,-456.8,87 };
	double* dp = d;

	//double d[]的地址为:000000F7A79BF4C8
	printf("double d[]的地址为:%p\n", d);
	//double* dp的地址为:000000F7A79BF4C8
	printf("double* dp的地址为:%p\n", dp);

	//double d[0]的地址为:000000F7A79BF4C8,double d[1]的地址为:000000F7A79BF4D0,double d[2]的地址为:000000F7A79BF4D8
	printf("double d[0]的地址为:%p,double d[1]的地址为:%p,double d[2]的地址为:%p\n", &d[0], &d[1], &d[2]);
	//double* dp[1]的地址为:000000F7A79BF4C8
	printf("double* dp[1]的地址为:%p\n", &dp[0]);
	//double* dp+1的地址为:000000F7A79BF4D8
	printf("double* dp+1的地址为:%p\n", dp + 2);
	
}