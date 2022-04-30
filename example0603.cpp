#include <stdio.h>
#include <string.h>

/*
==>
	strcpy能把strSrc的内容复制到strDest，为什么还要char * 类型的返回值？
		答：为了实现链式表达式。例如 int length = strlen( strcpy( strDest, “hello world”) );
<==
*/


/*
	自定义指针法字符串拷贝函数
*/
char* customPointerStrCpy(char* destination, const char* source)
{
	char* tmp = destination;
	while (*tmp++ = *source++) {}
	return destination;
}

/*
	自定义指针发字符串连接函数
*/
char* customPointerStrCat(char* dst, const char* src)
{
	char* tmp = dst;
	while (*tmp)
	{
		tmp++;
	}
	while (*tmp++ = *src++) {}
	return dst;
}

/*
	自定义指针发字符串比较函数
*/
void customPointerStrCmp(const char* dst, const char* src)
{
	const char* tmp = dst;
	while (*tmp && (*tmp++ == *src++)) {}
	if (*tmp - *src)
	{
		printf("比较字符串不相等!\n");
	}
	else
	{
		printf("比较字符串相等!\n");
	}
}

void example0603()
{
	printf("=====example0603()=====\n");

	char s1[] = "hello C!";
	char s2[40] = "Hello Java!";

	printf("字符串操作前:s1=%s,s2=%s\n", s1, s2);

	customPointerStrCpy(s2, s1);
	printf("字符串拷贝后:s1=%s,s2=%s\n", s1, s2);

	customPointerStrCat(s2, s1);
	printf("字符串连接后:s1=%s,s2=%s\n", s1, s2);

	customPointerStrCmp(s2, s1);
	customPointerStrCmp(s1, "hello C!");
	customPointerStrCmp("hello C!", "hello C!");

	char s3[40] = "Hello Java0";
	customPointerStrCat(s3, s1);
	printf("字符串连接后:s1=%s,s2=%s\n", s1, s3);

}