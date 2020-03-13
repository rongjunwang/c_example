#include<stdio.h>
#include<string.h>
int main()
{
	char user[20] = {"mrsoft"};
	char password[20] = {"mrkj"};
	char ustr[20],pwstr[20];
	int i=0;

	while(i<3)
	{
		printf("输入用户名字符串\n");
		gets(ustr);

		printf("输入密码字符串\n");
		gets(pwstr);

		if(strcmp(user,ustr))
		{
			printf("用户名字符串输入错误\n");
		}
		else
		{
			if(strcmp(password,pwstr))
			{
				printf("密码字符串输入错误\n");
			}
			else
			{
				printf("欢迎光临\n");
				break;
			}
		}
		i++;
	}
	if(i==4)
	{
		printf("输入字符串错误三次\n");
	}
	return 0;
}