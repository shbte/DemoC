#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
==>
_countof()：获取元素个数(字节 byte)
	没有声明数组大小的情况下，结果为数组的实际元素个数(花括号内的数组元素个数)。
	在声明数组大小的情况下，结果为声明的数组大小，而非数组的实际元素个数。
sizeof()：数组的总位数(位 bit)
	没有声明数组大小的情况下，结果为数组的实际元素个数(花括号内的数组元素个数)。
	在声明数组大小的情况下，结果为声明的数组大小，而非数组的实际元素个数。
stelen()：获取元素个数(字节 byte)
	char类型数组中，0和'\0'是结尾符，但'0'不是结尾符，以双引号""定义的数组会默认结尾有结尾符。
	没有声明数组大小的情况下，结果为寻找到结尾符为止(长度可能会超过想象)。
	在声明数组大小的情况下，有结尾符时，结果为结尾符前的元素个数，没有结尾符时，结果为数组的元素个数。
<==
_countof():能放几个元素
sizeof():这个单位空间是多少
strlen():这个空间使用了多少
_msize():malloc 或 new 出来的空间大小
*/
void example0501()
{
	printf("=====example0501()=====\n");

	int iStr1[] = { 1, 2, 3, 4, 5 };
	int iStr2[] = { 0, 1, 2, 3, 4, 5, 0 };
	int iStr3[] = { '0', '1', '2', '3', '4', '5', '6', '7', '0' };
	int iStr4[] = { '0', '1', '2', '3', '4', '5', '6', '7', '\0' };
	
	int iStr5[8] = { 1, 2, 3, 4, 5 };
	int iStr6[12] = { 0, 1, 2, 3, 4, 5, 0 };
	int iStr7[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '0' };
	int iStr8[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '\0' };

	//_countof()：获取元素个数(字节 byte)
	//没有声明数组大小的情况下，结果为数组的实际元素个数(花括号内的数组元素个数)。
	//在声明数组大小的情况下，结果为声明的数组大小，而非数组的实际元素个数。
	int strLen;
	strLen = _countof(iStr1);
	//_countof(iStr1)=5
	printf("_countof(iStr1)=%d\n", strLen);
	strLen = _countof(iStr2);
	//_countof(iStr2)=7
	printf("_countof(iStr2)=%d\n", strLen);
	strLen = _countof(iStr3);
	//_countof(iStr3)=9
	printf("_countof(iStr3)=%d\n", strLen);
	strLen = _countof(iStr4);
	//_countof(iStr4)=9
	printf("_countof(iStr4)=%d\n", strLen);
	strLen = _countof(iStr5);
	//_countof(iStr5)=8
	printf("_countof(iStr5)=%d\n", strLen);
	strLen = _countof(iStr6);
	//_countof(iStr6)=12
	printf("_countof(iStr6)=%d\n", strLen);
	strLen = _countof(iStr7);
	//_countof(iStr7)=16
	printf("_countof(iStr7)=%d\n", strLen);
	strLen = _countof(iStr8);
	//_countof(iStr8)=20
	printf("_countof(iStr8)=%d\n", strLen);

	//sizeof()：数组的总位数(位 bit)
	//没有声明数组大小的情况下，结果为数组的实际元素个数(花括号内的数组元素个数)。
	//在声明数组大小的情况下，结果为声明的数组大小，而非数组的实际元素个数。
	strLen = sizeof(iStr1);
	//sizeof(iStr1)=20 20=5*4
	printf("sizeof(iStr1)=%d\n", strLen);
	strLen = sizeof(iStr2);
	//sizeof(iStr2)=28 28=7*4
	printf("sizeof(iStr2)=%d\n", strLen);
	strLen = sizeof(iStr3);
	//sizeof(iStr3)=36 36=9*4
	printf("sizeof(iStr3)=%d\n", strLen);
	strLen = sizeof(iStr4);
	//sizeof(iStr4)=36 36=9*4
	printf("sizeof(iStr4)=%d\n", strLen);
	strLen = sizeof(iStr5);
	//sizeof(iStr5)=32 32=8*4
	printf("sizeof(iStr5)=%d\n", strLen);
	strLen = sizeof(iStr6);
	//sizeof(iStr6)=48 48=12*4
	printf("sizeof(iStr6)=%d\n", strLen);
	strLen = sizeof(iStr7);
	//sizeof(iStr7)=64 64=16*4
	printf("sizeof(iStr7)=%d\n", strLen);
	strLen = sizeof(iStr8);
	//sizeof(iStr8)=80 80=20*4
	printf("sizeof(iStr8)=%d\n", strLen);

	char cStr1[] = { 1, 2, 3, 4, 5 };
	char cStr2[] = { 0, 1, 2, 3, 4, 5, 0 };
	char cStr3[] = { '0', '1', '2', '3', '4', '5', '6', '7', '0' };
	char cStr4[] = { '0', '1', '2', '3', '4', '5', '6', '7', '\0' };
	char cStr5[] = "012345";
	
	char cStr6[8] = { 1, 2, 3, 4, 5 };
	char cStr7[12] = { 0, 1, 2, 3, 4, 5, 0 };
	char cStr8[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '0' };
	char cStr9[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '\0' };
	char cStr10[25] = "012345";

	//stelen()
	//char类型数组中，0和'\0'是结尾符，但'0'不是结尾符，以双引号""定义的数组会默认结尾有结尾符。
	//没有声明数组大小的情况下，结果为寻找到结尾符为止(长度可能会超过想象)。
	//在声明数组大小的情况下，有结尾符时，结果为结尾符前的元素个数，没有结尾符时，结果为数组的元素个数。
	strLen = strlen(cStr1);
	//strlen(cStr1)=32
	printf("strlen(cStr1)=%d\n", strLen);
	strLen = strlen(cStr2);
	//strlen(cStr2)=0
	printf("strlen(cStr2)=%d\n", strLen);
	strLen = strlen(cStr3);
	//strlen(cStr3)=56
	printf("strlen(cStr3)=%d\n", strLen);
	strLen = strlen(cStr4);
	//strlen(cStr4)=8
	printf("strlen(cStr4)=%d\n", strLen);
	strLen = strlen(cStr5);
	//strlen(cStr5)=6
	printf("strlen(cStr5)=%d\n", strLen);
	strLen = strlen(cStr6);
	//strlen(cStr6)=5
	printf("strlen(cStr6)=%d\n", strLen);
	strLen = strlen(cStr7);
	//strlen(cStr7)=0
	printf("strlen(cStr7)=%d\n", strLen);
	strLen = strlen(cStr8);
	//strlen(cStr8)=9
	printf("strlen(cStr8)=%d\n", strLen);
	strLen = strlen(cStr9);
	//strlen(cStr9)=8
	printf("strlen(cStr9)=%d\n", strLen);
	strLen = strlen(cStr10);
	//strlen(cStr10)=6
	printf("strlen(cStr10)=%d\n", strLen);
}