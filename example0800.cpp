#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
==>
	数组做参数时，数组会退化为指针，而sizeof(数组名)和sizeof(指针)是有区别的，所以需要传入所需的数组大小。
		sizeof(指针)是指针变量的大小(本身所占的内存字节数均为8,也就是要使用8个字节的大小来存储指针的值)，不是计算指针类型的大小(字节)。
		_countof和sizeof会计算字符串数组的结尾符，真实字符串长度应减一。
		使用strlen更好，不会计算字符串数组的结尾符。
	fopen：打开并获取文件流。fclose：关闭打开的文件流。
	fread：从文件中读取内容。fwrite：往文件中写入内容。
	fseek：将文件位置指针移动到指定位置，第二个参数为偏移量，第三个参数为偏移起点。
		SEEK_SET(0)：文件头
		SEEK_CUR(1)：当前位置
		SEEK_END(2)：文件尾
	ftell：将文件位置指针移动到文件头。
	malloc：在内存中开辟空间。free：回收内存空间。
<==
*/
//从文件读取内容
void readFile(const char* fileName)
{
	char fileMode[] = "r";
	if (fileName)
	{
		size_t fileSize = 0;
		FILE* pFile = fopen(fileName, fileMode);
		//将文件位置指针移动到尾部
		fseek(pFile, 0, SEEK_END);
		//获取文件位置指针的当前位置相对于文件首的偏移字节数
		fileSize = ftell(pFile);
		//将文件位置指针重新移动到头部
		//fseek(pFile, 0, 0);
		rewind(pFile);

		if (pFile)
		{
			char* buffer;
			//开辟空间接收文件内容，+1是为了追加结尾符
			buffer = (char*)malloc(fileSize * sizeof(char) + 1);
			size_t readSize = 0;
			if (buffer)
			{
				readSize = fread(buffer, (size_t)sizeof(char), fileSize, pFile);
				//添加结尾符，没有结尾符会向后寻找结尾符，导致控制台内容输出错误
				*(buffer + fileSize) = '\0';
				if (readSize)
					printf("文件内容：%s\n", buffer);
				else
					printf("文件内容为空，请检查文件。(%s)\n", fileName);
			}
			free(buffer);
		}
		else
			perror("文件读取错误，请检查文件是否存在。\n");
		fclose(pFile);
	}
	else
		printf("文件路径为空，请检查后再试。\n");
}

//将内容写入文件 
void writeFile(const char* fileName, char* pArray, size_t nArray, char fileMode[])
{
	if (fileName)
	{
		FILE* pFile = fopen(fileName, fileMode);

		if (pFile)
		{
			size_t writeSize = 0;
			//数组做参数时，数组会退化为指针，而sizeof(数组名)和sizeof(指针)是有区别的，所以需要传入所需的数组大小
			//writeSize = fwrite(pArray, sizeof(char), sizeof(pArray)/sizeof(char), pFile);
			writeSize = fwrite(pArray, (size_t)sizeof(char), nArray, pFile);

			if (writeSize)
				printf("内容写入文件成功。(%s)\n", fileName);
			else
				printf("内容写入文件失败。(%s)\n", fileName);
			fclose(pFile);
		}
		else
			printf("文件状态异常，写入错误，请检查。(%s)\n", fileName);
	}
}

void example0800()
{
	printf("=====example0800()=====\n");

	char cArray[] = "abcde吕鑫老师";
	char fileName[] = "C:/Users/luzhichao/Desktop/VS/File/myFile.txt";
	char fileMode[] = "a";

	readFile(fileName);

	//数组做参数时，数组会退化为指针，而sizeof(数组名)和sizeof(指针)是有区别的，所以需要传入所需的数组大小
	size_t nArray = 0;
	//_countof会计算字符串数组的结尾符，真实字符位数应减一
	//nArray = _countof(cArray);
	nArray = strlen(cArray);
	writeFile(fileName, cArray, nArray, fileMode);

	readFile(fileName);
}