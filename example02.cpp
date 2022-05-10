#include <stdio.h>

/*
	==>
		在一个cpp文件中调用另一个cpp文件中的方法：函数调用声明法
			在第12行声明函数后，就可以在后面调用该函数了
	<==
*/
void example02()
{
	puts("");
	printf("↓↓↓↓↓example0200.cpp ==> example0200(int i)↓↓↓↓↓\n");
	int example0200(int i);
	example0200(2);
}