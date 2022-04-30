#include <stdio.h>
#include <string.h>

/*
	计算数组长度

	参数是地址型变量(指针变量),而不是变量本身
*/
int StringLength(char str[])
{
	int i = 0;
	while (str[i])
		++i;
	return i;
}

/*
	字符串数组类型定义与输出

==>
	定义了长度的数组,系统会自动加上结尾符.没有定义长度的数组,系统并不会自动加上结尾符,会一直去寻找结尾符.
	0xcccc=烫
	低字节，高地址。高字节，低地址。----->大端存储
	低字节，低地址。高字节，高地址。----->小端存储
	计算数组长度函数:strlen<strlen>
<==
*/
void example0500()
{
	printf("=====example0500()=====\n");

	char a[20] = { 97,98,100,101,48 };
	char b[20] = { 'b','b','b','b','0' };
	char c[20] = "ccccccccccccc";
	//低字节，高地址。高字节，低地址。----->大端存储
	//低字节，低地址。高字节，高地址。----->小端存储
	//因为数组d没有定义结尾符,数组d会从低地址到高地址(低字节到高字节)寻找结尾符,最终在数组e中找到结尾符而结束数组d的打印.
	char d[] = { 'd','d','d','d','0' };
	char e[] = { 'e','e','e','e','\0' };
	char s[] = "sssssssssssss";

	puts(a);
	puts(b);
	puts(c);
	puts(d);
	puts(e);
	puts(s);

	printf("sizeof(a)=%d, StringLength(a)=%d\n", (int)sizeof(a), (int)strlen(a));
	printf("sizeof(b)=%d, StringLength(b)=%d\n", (int)sizeof(b), (int)strlen(b));
	printf("sizeof(c)=%d, StringLength(c)=%d\n", (int)sizeof(c), StringLength(c));
	printf("sizeof(d)=%d, StringLength(d)=%d\n", (int)sizeof(d), StringLength(d));
	printf("sizeof(e)=%d, StringLength(e)=%d\n", (int)sizeof(e), StringLength(e));
	printf("sizeof(s)=%d, StringLength(s)=%d\n", (int)sizeof(s), StringLength(s));
}