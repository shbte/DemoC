#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
==>
	
<==
*/
//从文件读取内容
void readFile(const char* fileName, char* buffer, int nCount)
{
	char fileMode[] = "r";
	if (fileName)
	{
		FILE* pFile = fopen(fileName, fileMode);
		if (pFile)
		{
			int result = 0;
			result = fread(buffer, sizeof(char), nCount, pFile);
			if (result)
			{
				printf("文件内容：%s\n", buffer);
			}
			fclose(pFile);
		}
		else
			perror("文件读取错误，请检查文件是否存在。");
	}
}

//将内容写入文件
void writeCharFile(const char* fileName, char array[], const char* mode)
{
	FILE* pFile = fopen(fileName, mode);
	if (pFile)
	{
		int result = 0;
		result = fwrite(array, sizeof(char), sizeof(array), pFile);
		if (result)
		{
			printf("内容写入文件成功。(%s)\n", fileName);
		}
		else
		{
			printf("内容写入文件失败。(%s)\n", fileName);
		}
		fclose(pFile);
	}
	else
	{
		printf("文件状态异常，请检查。(%s)\n", fileName);
	}
}

void example0800()
{
	char buffer[30];
	char cArray[] = "abcdef";

	char fileName[] = "C:/Users/luzhichao/Desktop/VS/File/myFile.txt";

	readFile(fileName , buffer, _countof(cArray));

	writeCharFile(fileName, cArray, "w");

	readFile(fileName, buffer, _countof(cArray));
}