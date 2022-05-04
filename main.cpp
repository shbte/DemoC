#include <stdio.h>

#include "example.h"

void callWork() {
	void dayWork();
	dayWork();
}

// 从上往下制，如果callExample在main下面，那么callExample方法将找不到而报错
void callExample()
{
	example();
}

int main() {

	// puts和printf的区别：puts会自动换行，只能输出字符没有格式控制。
	puts("Hello C!");

	//callWork();
	callExample();

	return 0;
}