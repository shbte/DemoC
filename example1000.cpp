#include <stdio.h>

/*
	指针
		一级指针：*p
		二级指针：**p
		n级指针：**..**p
		数组(数组名实际上就是定位数组第一个元素的位置，不可更改：++)：a[]
		指针数组(为数组，该数组的内容是，指向指定类型变量的指针)：char* p[]
			char* p[] = {"C语言指针数组"};
			上面p为指针数组，有一个元素，为char类型指针，该指针指向的内容是(C语言指针数组)
		数组指针(为指针，该指针指向的是，n个元素的p数组)：char (*p)[n]
			正确定义：
				int tmp[3] = {1,2,3};
				int (*p)[3] = &tmp;
			错误定义：
				1、int (*p)[3] = {1,2,3};
				2、int tmp[3] = {1,2,3};int (*p)[3] = tmp;
		二维数组(使用数组指针来访问二维数组)：int a[][]
			int a[2][4] = int (*a)[4]
				上面是定义了两个指针(*a)，每个指针都指向一个大小为4的数组。
				上面a之间a+1相隔4个int类型变量，a指向的是a[0][0]，a+1指向的是a[1][0]。
			数组指针访问二维数组：
			例：*(*(a+1)+2)指向的是a[1][2]
				*(array + i) == array[i]
				*(*(array + i) + j) == array[i][j]
				*(*(*(array + i) + j) + k) == array[i][j][k]
		常量指针(指向常量的指针，保护指针的地址不变)：
			const int* p
			const* int p
*/
void example1000()
{
	printf("=====example1000()=====\n");

	//常量指针数组
	const char* p1[5] = {
		"人生苦短，我用Python。",
		"PHP是世界上最好的语言！",
		"One more thing...",
		"一个好的程序员应该是那种过单行线都要往两边看的人。",
		"C语言很容易让你犯错误；C++看起来好一些，但当你用它时，你会发现会死的更惨。"
	};
	int i = 0;
	for (i; i < 5; i++)
	{
		printf("i=%d\n", i);
		printf("%s\n", p1[i]);		//下标法
		printf("%s\n", *(p1+i));	//指针法
	}


	//数组指针
	int temp[5] = { 1, 2, 3, 4, 5 };

	//{}是一维数组，属于一级引用，而数组指针属于二级引用，一级引用需要取地址才能给二级赋值
	//int(*p2)[5] = { 1, 2, 3, 4, 5 };
	
	//temp是指向数组的第一个元素，不是指向数组，属于一级引用，指针p2是指向数组，属于二级引用，所以赋值错误
	//int(*p2)[5] = temp;

	//一维数组取地址后属于二级引用，可以正常赋值
	int(*p2)[5] = &temp;

	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(*(p2 + 0) + i));	//*(*(p2 + 0) + i) = p2[0][i]
	}
	printf("\n");


	//二维数组
	int array[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};
	//数组指针
	int(*p)[4];
	int j;
	//二维数组属于二级引用，数组指针也属于二级引用，可以正常赋值
	p = array;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", p[i][j]);
			printf("%2d ", *(*(p + i) + j));
		}
		printf("\n");
	}


	const char* Books[] = {
		"《C专家编程》",
		"《C和指针》",
		"《C的陷阱与缺陷》",
		"《C Primer Plus》",
		"《Python基础教程（第三版）》"
	};
	const char* Python;
	const char* CLang[4];

	Python = Books[4];
	CLang[0] = Books[0];
	CLang[1] = Books[1];
	CLang[2] = Books[2];
	CLang[3] = Books[3];

	//《Python基础教程（第三版）》,《C专家编程》,《C和指针》,《C的陷阱与缺陷》,《C Primer Plus》
	printf("%s,%s,%s,%s,%s\n", Python, *CLang, *(CLang + 1), *(CLang + 2), *(CLang + 3));
}
