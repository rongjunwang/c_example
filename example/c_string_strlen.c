#include<stdio.h>
#include<string.h>
int main()
{
	char text[20],connect[50];
	int num;

	printf("输入一个字符串\n");
	gets(text);
	num = strlen(text);
	printf("字符串的长度：%d\n",num);

	printf("在输入一个字符串\n");
	gets(connect);
	num = strlen(connect);
	printf("字符串的长度为：%d\n",num);

	//连接字符串
	printf("连接字符串\n");
	strcat(text,connect);
	num = strlen(text);
	printf("连接字符串之后长度%d\n",num);

	return 0;
}