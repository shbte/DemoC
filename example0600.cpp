#include <stdio.h>

/*
==>
	*:获取地址值指向的内容
	&:获取地址值所在(指针变量本身)的地址值

	指针变量也是有不同类型的的,例如:int*,char*
	指针变量+n=指针地址的值+指针变量的字节大小*n

	指针的大小为8(无符号整型,16位=2btye,32位=4byte,64位=8btye)
	指针变量的大小根据定义指针的类型(指针所指向的内容的类型)决定,例:char* 1,int* 4
<==
*/
void example0600()
{
	printf("=====example0600()=====\n");

	int i = 78;
	int* ip = &i;

	//i=78,变量i的值
	printf("i=%d\n", i);
	//&i=00000014D7FEF054,变量i的地址值
	printf("&i=%p\n", &i);
	//ip=00000014D7FEF054,变量i的地址值
	printf("ip=%p\n", ip);
	//&ip=00000014D7FEF078,指针变量ip的地址值
	printf("&ip=%p\n", &ip);
	//*ip=78,指针变量ip的值
	printf("*ip=%d\n", *ip);
	//&*ip=00000014D7FEF054,指针变量ip的值(变量i)的地址值
	printf("&*ip=%p\n", &*ip);

	//size(i)=4,sizeof(ip)=8,sizeof(*ip)=4
	printf("size(i)=%d,sizeof(ip)=%d,sizeof(*ip)=%d\n", (int)sizeof(i), (int)sizeof(ip), (int)sizeof(*ip));

	//i+1=79,ip+2=00000014D7FEF05C
	//00000014D7FEF05C=00000014D7FEF054+sizeod(int 4)*n
	printf("i+1=%d,ip+2=%p\n", i + 1, ip + 2);

	//"int *"类型的的值不能用于初始化"char *"类型的实体
	//char* cp = &i;

	//c1是指针变量(char *),c2是char变量
	char* c1, c2;
	//c3是指针变量,c4是指针变量
	char* c3, * c4;
	char c5 = 65;
	char c6 = 66;

	c1 = &c5;
	//不能将"char *"类型的值分配到"char"类型的实体
	//c2 = &c5;
	c2 = c5;
	c3 = &c5;
	//使用未初始化的内存"c4",需要先指向内存地址,然后才能赋值
	//*c4 = c5;
	c4 = &c5;
	//更改了c5的值,所有指向c5指针的值都改变
	*c4 = c6;

	//c1=000000CAEEEFF6B4
	printf("c1=%p\n", c1);
	//&c2=000000CAEEEFF654
	printf("&c2=%p\n", &c2);
	//c3=000000CAEEEFF6B4
	printf("c3=%p\n", c3);
	//c4=000000CAEEEFF6B4
	printf("c4=%p\n", c4);
	//&c5=000000CAEEEFF6B4
	printf("&c5=%p\n", &c5);

	//*c1=66
	printf("*c1=%d\n", *c1);
	//c2=65
	printf("c2=%d\n", c2);
	//*c3=66
	printf("*c3=%d\n", *c3);
	//*c4=66
	printf("*c4=%d\n", *c4);
	//c5 = 66
	printf("c5=%d\n", c5);

	//size(c1)=8,sizeof(c2)=1,size(c3)=8,sizeof(c4)=8,size(c5)=1,sizeof(c6)=1
	printf("size(c1)=%d,sizeof(c2)=%d,size(c3)=%d,sizeof(c4)=%d,size(c5)=%d,sizeof(c6)=%d\n", (int)sizeof(c1), (int)sizeof(c2), (int)sizeof(c3), (int)sizeof(c4), (int)sizeof(c5), (int)sizeof(c6));
	//size(c1)=8,sizeof(c3)=8,size(c4)=8,sizeof(*c1)=1,size(*c3)=1,sizeof(*c4)=1
	printf("size(c1)=%d,sizeof(c3)=%d,size(c4)=%d,sizeof(*c1)=%d,size(*c3)=%d,sizeof(*c4)=%d\n", (int)sizeof(c1), (int)sizeof(c3), (int)sizeof(c4), (int)sizeof(*c1), (int)sizeof(*c3), (int)sizeof(*c4));

	//c1+3=000000E33D3AF257(c1=000000E33D3AF254)
	//000000E33D3AF257=000000E33D3AF254+sizeof(char 1)*n
	printf("c1+3=%p\n", c1 + 3);

}