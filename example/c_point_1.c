/*
* *表示取地址的变量值，&表示取变量值的地址
*/
#include<stdio.h>
int main()
{
	int a,b;
	int *ipointer1, *ipointer2;		//ipointer1代表地址，*ipointer1代表变量值
	scanf("%d,%d",&a,&b);
	ipointer1 = &a;
	ipointer2 = &b;
	printf("the number is : %d,%d\n", *ipointer1, *ipointer2);
	return 0;
}