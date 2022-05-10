#include <stdio.h>
#include <math.h>

void work0801()
{
	printf("↓↓↓↓↓day08Work.cpp ==> work0801()↓↓↓↓↓\n");

	/*
	3、打印7列13行的菱形两角
	* 
	* * 
	* * *
	* * * * 
	* * * * * 
	* * * * * * 
	* * * * * * * 
	* * * * * * 
	* * * * * 
	* * * * 
	* * * 
	* * 
	* 
	*/

	int i = 0;
	//行打印
	for (i; i < 13; i++)
	{
		if (i < 7)
		{
			//上7行打印(0~7)
			int j = 0;
			for (j; j <= i; j++)
			{
				printf("* ");
			}
			puts("");
		} 
		else 
		{
			//下6行打印(7~12)
			int j = 13 - i;
			for (j; j > 0; j--)
			{
				printf("* ");
			}
			puts("");
		}
		
	}
}

void work0802()
{
	printf("↓↓↓↓↓day08Work.cpp ==> work0802()↓↓↓↓↓\n");

	/*
	4、打印13列7行的菱形两角
	0 1 2 3 4 5 6 7 8 9 A B C D
	              * 
	            * * * 
	          * * * * *
	        * * * * * * * 
	      * * * * * * * * * 
	    * * * * * * * * * * * 
	  * * * * * * * * * * * * * 
	*/

	int i = 0;
	//行打印
	for (i; i < 7; i++)
	{
		int j = 0;
		//列打印
		for (j; j < 14; j++)
		{
			if (7 - i > j)
			{
				//左空格打印
				printf("  ");
			}
			else if (14 - j < 7 - i)
			{
				//右空格打印
				printf("  ");
			}
			else 
			{
				//中间*打印
				printf("* ");
			}
		}
		puts("");
	}
}

void work0803()
{
	printf("↓↓↓↓↓day08Work.cpp ==> work0803()↓↓↓↓↓\n");

	/*
	5、打印13行13列完整的菱形。
	 01 2 3 4 5 6 7 8 9 A B C D
	0             *
	1           * * * 
	2         * * * * *
	3       * * * * * * * 
	4     * * * * * * * * * 
	5   * * * * * * * * * * * 
	6 * * * * * * * * * * * * * 
	7   * * * * * * * * * * * 
	8     * * * * * * * * * 
	9       * * * * * * * 
	A         * * * * * 
	B           * * * 
	C             * 
	*/

	int i = 0;
	//上7行打印
	for (i; i < 7; i++)
	{
		int j = 0;
		//列打印
		for (j; j < 14; j++)
		{
			if (7 - i > j)
			{
				//左空格打印
				printf("  ");
			}
			else if (14 - j < 7 - i)
			{
				//右空格打印
				printf("  ");
			}
			else
			{
				//中间*打印
				printf("* ");
			}
		}
		puts("");
	}
	//下6行打印
	for (i; i < 13; i++)
	{
		int j = 0;
		//列打印
		for (j; j < 14; j++)
		{
			if (i - 5 > j)
			{
				//左空格打印
				printf("  ");
			}
			else if (14 - j < i - 5)
			{
				//右空格打印
				printf("  ");
			}
			else
			{
				//中间*打印
				printf("* ");
			}
		}
		puts("");
	}
}

void work0804()
{
	puts("");
	printf("↓↓↓↓↓day08Work.cpp ==> work0804()↓↓↓↓↓\n");

	int n = 1;
	while (((int)pow(2, n) % 7 == 0))
	{
		if (n == 100)
			printf("n = 10000");
		n++;
	}
	printf("pow(2,n)=%d\n",(int)pow(2,n));
	printf("2^%d \% 7 == 0\n", n);
}

void work0805()
{
	puts("");
	printf("↓↓↓↓↓day08Work.cpp ==> work0805()↓↓↓↓↓\n");

	char c = 1;
	short s = 1;
	int i = -658;
	long l = 1;
	float f = -78.375;
	double d = 1;

	printf("char c = %d\n", c);
	printf("short s = %d\n", s);
	printf("int i = %d\n", i);
	printf("long l = %d\n", l);
	printf("float f = %5.20f\n", f);
	printf("double d = %5.20f\n", d);
}

void day08Work()
{

	work0801();

	puts("");
	work0802();

	puts("");
	work0803();

	//work0804();

	work0805();
}