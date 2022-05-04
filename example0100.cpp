#include <stdio.h>

/*
	C语言数据类型：基本类型、结构类型、指针类型、空类型(void)
		基本类型：数值类型、字符类型
			数值类型：整型(短整型short、整形int、长整型long)、浮点型(单精度型float、双精度型double)
			字符类型：char
		结构类型：数组、结构体(struct)、共用体(union)、枚举(enum)

	==>
		单个字符类型无法在控制台输入，因为换行时"\n"会进行覆盖输入。
	<==
*/
void example0100()
{
	printf("=====example0100()=====\n");

	// 基本类型：数值类型（整型、浮点型）、字符类型
	// 整型：短整型、整型、长整型
	short a = 001;
	int b = 002;
	long c = 003;
	// 浮点型：单精度型、双精度型
	float d = 004.01f;
	double e = 005.020l;
	// 字符类型
	char f = 'a';

	// scanf函数:输入函数
	printf("输入短整型：");
	scanf_s("%hd", &a);
	printf("输入整型：");
	scanf_s("%d", &b);
	printf("输入长整型：");
	scanf_s("%ld", &c);
	printf("输入单精度型：");
	scanf_s("%f", &d);
	printf("输入双精度型：");
	scanf_s("%lf", &e);
	//printf("输入字符类型：");
	// 换行时"\n"会替换输入的内容，基本无法在控制台输入char类型数据(非数组char类型)
	//scanf_s("%c", &f, 1);
	

	printf("短整型:%hd，整型:%d，长整型:%ld，单精度型:%g，双精度型:%g，字符类型：%c\n", a, b, c, d, e, f);
}