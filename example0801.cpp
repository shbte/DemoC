#include <stdio.h>

/*
==>
	进入if循环的条件为非0，不单单是1。以下条件都可以进入循环
		!NULL
		-1
		"abcd"
		"吕鑫老师"
<==
*/
void example0801()
{
	printf("=====example0801()=====\n");

	if (!NULL)
		puts("!NULL进入了循环。");
	if (-1)
		puts("-1进入了循环。");
	if ("abcd")
	{
		puts("abcd进入了循环。");
	}
	if ("吕鑫老师")
	{
		puts("吕鑫老师进入了循环。");
	}
	if (88.09)
	{
		puts("88.09进入了循环。");
	}
}