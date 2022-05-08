#include <stdio.h>

/*
	==>
		1、scanf_s()的使用方法，需要在变量后加变量大小(位数)。
		2、基本数据类型在scanf输入时，都应该用地址&，字符变量可以不加，但为了严谨还是加&。
	<==
*/
void example0300()
{
	printf("=====example0300()=====\n");

	int nNumb = 15;
	char sName[20];
	printf("请输入一个员工的工号、姓名【以空格间隔】：");
	// 数值类型还是需要加&的
	// 对于sName来说，字符类型&加不加都不影响，但是还是加吧,sName和&sName在内存中是同一个地址值
	scanf_s("%d %s", &nNumb, &sName, 20);

	printf("你输入的工号：%d \n", nNumb);
	printf("你输入的姓名：%s \n", sName);
}