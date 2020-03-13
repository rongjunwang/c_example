#include<stdio.h>
void main(int argc,char *argv[])
{
	printf("the list of parameter\n");
	printf("命令名：\n");
	printf("%s\n",*argv);
	printf("%5d\n",*argv[1]);
	printf("参数个数：\n");
	printf("%d\n", argc);
}