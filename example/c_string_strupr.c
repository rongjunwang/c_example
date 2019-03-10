/*
* strupr,strlwr 函数不是标准库，gcc没有函数
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char text[20],change[20];
	int num;
	int i=0;
	while(1)
	{
		printf("输入大小写转换方式\n");
		scanf("%d",&num);

		printf("输入一个字符串\n");
		gets(text);
		if(num == 1)
		{
			strcpy(change,text);
			strupr(change);
			printf("转换成大写字母：%s\n",change);
		}
		else if(num == 2)
		{
			strcpy(change,text);
			strlwr(change);
			printf("转换成小写字母：%s\n",change);
		}
		else if(num == 0)
		{
			break;
		}
	}
	return 0;
}