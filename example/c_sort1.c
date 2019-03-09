/*
* 冒泡排序
*/
#include<stdio.h>
int main(){
	int i,j;
	int a[10];
	int iTemp;
	printf("为数组元素赋值\n");

	//手动赋值
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	//冒泡排序
	for(i=1;i<10;i++)
	{
		for(j=9;j>=i;j--)
		{
			if(a[j]<a[j-1])
			{
				iTemp = a[j-1];
				a[j-1] = a[j];
				a[j] = iTemp;
			}
		}
	}

	//输出数组
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
		if(i==4) printf("\n");
	}
	return 0;
}