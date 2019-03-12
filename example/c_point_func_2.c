#include<stdio.h>
int *per(int a,int b);
int Perimeter;
void main()
{
	int iWidth,iLength;
	int *iResult;
	printf("请输入长方形的长：\n");
	scanf("%d",&iLength);
	printf("请输入长方形的宽：\n");
	scanf("%d",&iWidth);
	iResult = per(iWidth,iLength);
	printf("长方形的周长是：\n");
	printf("%d\n",*iResult);
}
int *per(int a,int b)
{
	int *p;
	p=&Perimeter;
	Perimeter=(a+b)*2;
	return p;
}