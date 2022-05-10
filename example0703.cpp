#include <stdio.h>
#include <string.h>

/*
==>
	结构体的定义,定义时并没有申请内存空间(变量在定义时就会申请内存空间),结构体在构建对象时才会进行内存空间申请
	typedef关键字为结构体重新命名:
		第一种:重命名和定义同时进行
		第二种:先定义结构体,再重新为结构体命名
	结构体对象赋值的三种方式:使用赋值符号(=)、调用memcpy函数丶逐个成员变量的数据复制
		字符串数组不能直接使用赋值符号进行数据赋值,需要使用strcpy函数进行赋值
<==
*/

//结构体的定义,定义时并没有申请内存空间(变量在定义时就会申请内存空间),结构体在构建对象时才会进行内存空间申请
struct SWork1
{
	int iNumber; //工号
	char sName[20]; //姓名
	float fSala; //工资
};

//typedef关键字为结构体重新命名
//第一种:重命名和定义同时进行
typedef struct SWork2
{
	int iNumber;
	char sName[20];
	float fSala;

}SWork3;

//第二种:先定义结构体,再重新为结构体命名
struct SWork4
{
	int iNumber;
	char sName[20];
	float fSals;
};
typedef SWork4 SWork5;

void example0703()
{
	printf("=====example0703()=====\n");

	SWork1 w1 = {};
	SWork2 w2 = { 8001, "张三", 9000 };

	//工号:0,姓名:,工资:0.000000
	printf("SWork1 ==> 工号:%d,姓名:%s,工资:%f\n", w1.iNumber, w1.sName, w1.fSala);
	//工号:8001,姓名:张三,工资:9000.000000
	printf("SWork2 ==> 工号:%d,姓名:%s,工资:%f\n", w2.iNumber, w2.sName, w2.fSala);
	
	//结构体对象赋值的三种方式:使用赋值符号、调用memcpy函数和逐个成员变量的数据复制

	//使用赋值符号
	SWork3 w3 = { 9889.8 };

	//SWork3 ==> 工号:9889,姓名:,工资:0.000000
	printf("SWork3 ==> 工号:%d,姓名:%s,工资:%f\n", w3.iNumber, w3.sName, w3.fSala);

	//w3(SWork3)是w2(SWork2)的重命名,所以w2可以给w3直接赋值
	w3 = w2;
	//w1 = w2; 结构体定义不同,不能直接赋值
	//(SWork2)w1 = w2; 结构体定义不同,不能强制转换

	//SWork3 ==> 工号:8001,姓名:张三,工资:9000.000000
	printf("SWork3 ==> 工号:%d,姓名:%s,工资:%f\n", w3.iNumber, w3.sName, w3.fSala);

	//逐个成员变量的数据赋值
	w3.iNumber = w2.iNumber;
	//w3.sName = w2.sName; 字符串数组不能直接使用赋值符号进行数据赋值,需要使用strcpy函数进行赋值
	strcpy_s(w3.sName, w2.sName);
	w3.fSala = 7000.89;
	//SWork3 ==> 工号:8001,姓名:张三,工资:7000.890137
	printf("SWork3 ==> 工号:%d,姓名:%s,工资:%f\n", w3.iNumber, w3.sName, w3.fSala);

	//调用memcpy函数进行赋值
	memcpy(&w3, &w2, sizeof(w2));
	//SWork3 ==> 工号:8001,姓名:张三,工资:9000.000000
	printf("SWork3 ==> 工号:%d,姓名:%s,工资:%f\n", w3.iNumber, w3.sName, w3.fSala);
}