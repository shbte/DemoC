#include <stdio.h>

void work0701()
{
	printf("↓↓↓↓↓day07Work.cpp ==> work0701()↓↓↓↓↓\n");

	/*
	1、如果打印十进制的对应十六进制可以通过乘以多少个16取余数来转换。
	请思考：如何编写一个循环来解决用户输入的任何十进制对应的十六进制？
	（当然不能直接%x）；默认是32位的数字，需要8次循环；
	请思考：如何完善打印大于9的十六进制数，
	比如：999999999打印出来的是3 11 9 10 12 9 15 15，
	如何打印成：3B9A C9FF 而且分为2堆（4个十六进制一堆）；
	*/

	unsigned int iNum, tmp_mod;
	char xNum[8] = "";
	// int：4个字节 0xFF FF FF FF
	printf("请输入不大于\"4294967295\"的十进制数：");
	scanf_s("%d", &iNum);
	tmp_mod = iNum;
	while (iNum >= 16)
	{
		tmp_mod = iNum % 16;
		printf("%X ", tmp_mod);

		iNum = iNum / 16;
	}
	printf("%d", tmp_mod);
}


void work0702()
{
	printf("↓↓↓↓↓day07Work.cpp ==> work0702()↓↓↓↓↓\n");

	/*
	3、继续完善九九乘法表的打印：
	a)试用%-3d这种打印方式，让矩形阵列不再七扭八歪的形状。
	b)继续完善九九乘法表，把矩形阵列变为斜三角形乘法表的阵列；
	*/

	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			//printf("%dx%d=%d\t", j, i, j * i);
			printf("%dx%d=%-3d", j, i, j * i);
		}
		puts("");
	}
}

void day07Work()
{
	//work0701();
	work0702();
}