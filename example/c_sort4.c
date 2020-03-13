/*
* 折半法排序
*/
#include<stdio.h>
//声明函数
void CelerityRun(int left,int right,int array[]);
int main()
{
	int i;
	int a[10];
	printf("为函数元素赋值\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	CelerityRun(0,9,a);

	//输出
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4) printf("\n");
	}
	return 0;
}
void CelerityRun(int left,int right,int array[])
{
	int i,j;
	int middle,iTemp;
	i = left;
	j = right;
	//求中间值
	middle = array[(left+right)/2];
	do
	{
		//从左找小于中间值的数
		while((array[i]<middle) && (i<right)) i++;
		//从右找大于中间值的数
		while((array[j]>middle) && (j>left)) j--;
		if(i<=j)
		{
			iTemp = array[i];
			array[i] = array[j];
			array[j] = iTemp;
			i++;
			j--;
		}
	}while(i<=j); //如果俩个下标交错，就停止（完成一次）

	//递归左半边
	if(left<j) CelerityRun(left,j,array);
	//递归右半边
	if(right>i) CelerityRun(i,right,array);
}