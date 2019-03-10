/*
* 插入法排序
*/
#include<stdio.h>
int main()
{
	int i;
	int a[10];
	int iTemp;
	int iPos;
	printf("为数组元素赋值\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	//从小到大排序
	for(i=1;i<10;i++)
	{
		iTemp = a[i];
		iPos = i-1;
		//寻找插入值的位置
		while((iPos>=0) && (iTemp<a[iPos]))
		{
			a[iPos+1] = a[iPos];
			iPos--;
		}
		a[iPos+1] = iTemp;
	}

	//输出数组
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4) printf("\n");
	}
	return 0;
}