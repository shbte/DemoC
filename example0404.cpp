#include <stdio.h>
/*
	==>
		打印类型变量的大小(字节数)：sizeof(类型变量)
	<==
*/
void example0404()
{
	printf("=====example0404()=====\n");

	char ch = 99;
	int n = 1234567890;
	float f = 12345678.123456789f;//0.123456f
	double d = 1234567890.1234567890;
	//0.01234567890123456789;
	//1234567890123456.0;
	printf("c=%c,n=%d,f=%f,d=%0.20lf\n", ch + 5, n, f, d);
	printf("sizeof(ch)=%d, sizeof(n)=%d, sizeof(f)=%d, sizeof(d)=%d\n",
	(int)sizeof(ch), (int)sizeof(n), (int)sizeof(f), (int)sizeof(d));
	//最后一行是打印所有类型变量的大小（字节数）
}