// 解除C标准安全警告
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int day02Work01()
{
	/*
	1、用scanf和printf等函数开发以下功能，假设一个班级有3个学生。
	定义3组变量，每一组包括：学号、姓名和一些学科成绩（数学、语文、英语）
	a)首先根据让用户输入3组测试数据到对应的3组变量中；
	b)（横向计算）并打印以上3组数据的学号姓名等信息，还有每个学生的3科总分和3科平均分；
	c)（纵向计算）并打印每门课程的平均分，以及3门课全班平均分；
	*/
	int n1, n2, n3;
	char s1[20], s2[20], s3[20];
	int m1, m2, m3;
	int c1, c2, c3;
	int e1, e2, e3;
	printf("请输入学生信息(学号 姓名 数学成绩 语文成绩 英语成绩)并以空格分隔\n例：001 小明 100 95 100\n");
	// C标准不允许使用scanf，如果要使用，可以在第一行解除安全警告。#define _CRT_SECURE_NO_WARNINGS
	printf("第一位学生信息：");
	scanf("%d %s %d %d %d", &n1, s1, &m1, &c1, &e1);
	printf("第二位学生信息：");
	scanf("%d %s %d %d %d", &n2, s2, &m2, &c2, &e2);
	printf("第三位学生信息：");
	scanf("%d %s %d %d %d", &n3, s3, &m3, &c3, &e3);

	printf("===学生信息输入完毕！===\n");
	printf("学生信息如下：\n学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t三科总分\t三科平均分\n");
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n1, s1, m1, c1, e1, m1 + c1 + e1, (m1 + c1 + e1) / 3.00);
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n2, s2, m2, c2, e2, m2 + c2 + e2, (m2 + c2 + e2) / 3.00);
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n3, s3, m3, c3, e3, m3 + c3 + e3, (m3 + c3 + e3) / 3.00);
	printf("数学平均分：%0.2f\t语文总分平均分：%0.2f\t英语总分平均分：%0.2f\t三科全班平均分：%g\n", (m1 + m2 + m3) / 3.00, (c1 + c2 + c3) / 3.00, (e1 + e2 + e3) / 3.00, (m1 + m2 + m3 + c1 + c2 + c3 + e1 + e2 + e3) / 3.00);

	return 0;
}

void day02Work02()
{
	/*
	2、换用scanf_s函数代替scanf函数来开发以上功能。

	在输入数值类型时，scanf和scanf_s的使用方式是一样的
	在输入字符类型时，scanf_s的使用方式有异↓：
		int a;
		char b;
		char s[20];
		scanf_s("%d %c %s", &a, c, 1, s, 20);
	*/

	int n1, n2, n3;
	char s1[20], s2[20], s3[20];
	int m1, m2, m3;
	int c1, c2, c3;
	int e1, e2, e3;
	printf("请输入学生信息(学号 姓名 数学成绩 语文成绩 英语成绩)并以空格分隔\n例：001 小明 100 95 100\n");
	// C标准不允许使用scanf，如果要使用，可以在第一行解除安全警告。#define _CRT_SECURE_NO_WARNINGS
	printf("第一位学生信息：");
	// 20是s1的位数
	scanf_s("%d %s %d %d %d", &n1, s1, 20, &m1, &c1, &e1);
	printf("第二位学生信息：");
	scanf_s("%d %s %d %d %d", &n2, s2, 20, &m2, &c2, &e2);
	printf("第三位学生信息：");
	scanf_s("%d %s %d %d %d", &n3, s3, 20, &m3, &c3, &e3);

	printf("学生信息输入完毕！\n");
	printf("学生信息如下：\n学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t三科总分\t三科平均分\n");
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n1, s1, m1, c1, e1, m1 + c1 + e1, (m1 + c1 + e1) / 3.00);
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n2, s2, m2, c2, e2, m2 + c2 + e2, (m2 + c2 + e2) / 3.00);
	printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%0.2f\n", n3, s3, m3, c3, e3, m3 + c3 + e3, (m3 + c3 + e3) / 3.00);
	printf("数学平均分：%0.2f\t语文总分平均分：%0.2f\t英语总分平均分：%0.2f\t三科全班平均分：%0.2f\n", (m1 + m2 + m3) / 3.00, (c1 + c2 + c3) / 3.00, (e1 + e2 + e3) / 3.00, (m1 + m2 + m3) / 3.00 + (c1 + c2 + c3) / 3.00 + (e1 + e2 + e3) / 3.00);
}