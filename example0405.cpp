#include <stdio.h>

/*
	==>
		打印有符号和无符号类型变量的大小(字节数)：sizeof(类型变量)
	<==
*/
void example0405()
{
	printf("=====example0405()=====\n");

	int m = -2;
	long long i = 0x80000000;
	unsigned long long u = 0xFFFFFFFF;
	printf("i=%I64d,u=%I64u\n", i * 5000, u * u);
	int len_i = sizeof(i);
	int len_u = sizeof(u);
	printf("long long sizeof(i)=%d,unsigned long long sizeof(u)=%d\n", len_i, len_u);
}