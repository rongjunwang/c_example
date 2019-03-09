/*
* 交换法排序
*/
#include<stdio.h>
int main()
{
	int i,j;
	int a[10];
	int iTemp;
	printf("为数组元素赋值\n");

	//赋值
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	//交换法排序
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[j] < a[i])
			{
				iTemp = a[i];
				a[i] = a[j];
				a[j] = iTemp;
			}
		}
	}

	//输出
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4) printf("\n");
	}
	return 0;
}