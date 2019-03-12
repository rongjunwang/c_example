/*
* pointer实现冒泡排序
*/
#include<stdio.h>
void order(int *p,int n)
{
	int i,t,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j) > *(p+j+1))
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
	printf("排序后的数组\n");
	for(i=0;i<n;i++)
	{
		if(i%5==0)
		{
			printf("\n");
		}
		printf("%5d",*(p+i));
	}
	printf("\n");
}
void main(){
	int a[20],i,n;
	printf("请输入数组元素的个数\n");
	scanf("%d",&n);
	printf("请输入各个元素\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	order(a,n);
}
