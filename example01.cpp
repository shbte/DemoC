#include <stdio.h>

#include "example0100.h"

/*
	==>
		在一个cpp文件中调用另一个cpp文件中的方法：定义头文件法
			第三行引用example0100.h的头文件后，就可以调用该头文件中的函数了
	<==
*/
void example01()
{
	printf("↓↓↓↓↓example0100.cpp ==> example0100()↓↓↓↓↓\n");
	example0100();
}