#include <stdio.h>
#include <stdlib.h>

void InputArray(int* p, int nLen)
{//对来源数组写入
	int i = 0;
	printf("请输入%d个整数：", nLen);
	while (i < nLen)
		scanf_s("%d", &p[i++]);//使用了数组下标法,相当于p为数组,&p[i]对数组取址
}

void InputPoniter(int* p, int nLen)
{//对来源数组写入
	int i = 0;
	printf("请输入%d个整数：", nLen);
	while (i++ < nLen)
		scanf_s("%d", p++);//使用了指针法,p为地址
}

int CalcalArray(int* p, int nLen)
{//对来源数组读取
	int nSum = 0;
	while (nLen--)
		nSum += p[nLen];//下标法
	return nSum;
}

int CalcalPoniter(int* p, int nLen)
{//对来源数组读取
	int nSum = 0;
	while (nLen--)
		nSum += *p++;//指针法
	return nSum;
}

void example0700() 
{
	printf("=====example0700()=====\n");

	int a[5], n;
	//InputArray(a, _countof(a));
	InputPoniter(a, _countof(a));
	n = CalcalArray(a, _countof(a));
	printf("你输入的数字总和为：%d\n", n);
}