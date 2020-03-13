/*
* a[3][20] 对于二位数组，如果字符少于20位，会浪费空间，用指针数组，会有效解决这个问题
*/
#include<stdio.h>
int main()
{
	int i;
	char *month[] = 
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	//输出
	for(i=0;i<12;i++)
	{
		printf("%s\n", month[i]);
	}
	return 0;
}