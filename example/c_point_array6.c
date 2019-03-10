#include<stdio.h>
int main()
{
	char str1[]="you are beautiful",str2[30],*p1,*p2;
	p1=str1;			//p1表示指针，str1是数组变量名，表示数组的指针
	p2=str2;
	while(*p1!='\0')
	{
		*p2=*p1;
		p1++;
		p2++;
	}
	//在字符串末尾加个结束符
	*p2='\0';
	printf("now the string2 is:\n");
	puts(str2);
}