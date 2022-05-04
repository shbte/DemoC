#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
==>
    静态局部变量在静态存储区分配空间,程序仅分配一次内存;函数返回后,该静态局部变量并不会消失.
    静态局部变量具有局部作用域,只对定义自己的函数体始终可见,函数推出后,变量还存在,但不可用.
<==
*/

char* __strtok_r(char* s, const char* delim, char** save_ptr)
{
    char* end;

    if (s == NULL)
        s = *save_ptr;

    if (*s == '\0')
    {
        *save_ptr = s;
        return NULL;
    }

    /* Scan leading delimiters.  */
    //检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。2
    unsigned int i = strspn(s, delim);
    s += i;
    if (*s == '\0')
    {
        *save_ptr = s;
        return NULL;
    }

    /* Find the end of the token.  */
    //检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符。4
    i = strcspn(s, delim);
    end = s + i;
    if (*end == '\0')
    {
        *save_ptr = end;
        return s;
    }

    /* Terminate the token and make *SAVE_PTR point past it.  */
    *end = '\0';
    *save_ptr = end + 1;
    return s;
}

char* _strtok(char* s, const char* delim)
{
    //定义静态局部变量保存分割后的剩余字符串
    static char* olds;
    return __strtok_r(s, delim, &olds);
}

void example0702()
{
	printf("=====example0702()=====\n");

	char str[] = "- This, a sample string.";
	char* pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = _strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
        //在strtok方法中定义了静态局部变量保存分割后的剩余字符串,所以arg1只需要传一次,后续传NULL
		pch = _strtok(NULL, " ,.-");
	}
}