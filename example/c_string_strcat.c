/*
* 连接字符串（注意连接之后字符串长度，不够会error）
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[30],str2[30];
	printf("输入目的字符串：\n");
	gets(str1);
	printf("输入源字符串：\n");
	gets(str2);

	printf("输出目的字符串：\n");
	puts(str1);
	printf("输出源字符串\n");
	puts(str2);

	//copy
	printf("调用strcat连接字符串\n");
	strcat(str1,str2);

	printf("连接字符串之后的目的字符串：\n");
	puts(str1);

	return 0;
}