/*
* 反转输出字符串
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char String[7] = {"mrsoft"};
	char Reverse[7] = {0};
	//计算字符串长度
	int size;
	size = sizeof(String);
	for(i=0;i<6;i++)
	{
		Reverse[size-i-2] = String[i];
	}

	printf("输出源字符串：%s\n",String);
	printf("输出目标字符串：%s\n",Reverse);
	return 0;
}