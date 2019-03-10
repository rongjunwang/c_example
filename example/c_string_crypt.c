/*
* 字符串加密解密
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int result = 1;
	int i;
	int count = 0;
	char Text[128] = {'\0'};   //定义明文字符串
	char cryptograph[128] = {'\0'}; //定义密文字符串
	while(1)
	{
		if(result == 1)			//明文字符串
		{
			printf("请输入明文字符串\n");
			gets(Text);
			count = strlen(Text);
			for(i=0;i<count;i++)
			{
				cryptograph[i] = Text[i] + i + 5;
			}
			cryptograph[i] = '\0';
			printf("加密后的字符串：%s\n",cryptograph);
		}
		else if(result == 2)
		{
			count =strlen(Text);
			for(i=0;i<count;i++)
			{
				Text[i] = cryptograph[i] - i - 5;
			}
			Text[i] = '\0';
			printf("加密后的明文是：%s\n",Text);
		}
		else if(result == 3)
		{
			break;
		}
		else
		{
			printf("请输入命令符\n");
		}

		//输出
		printf("输入1加密新的明文，输入2对刚加密的密文进行解密，输入3退出系统\n");
		printf("请输入命令符\n");
		scanf("%d",&result);
	}
}