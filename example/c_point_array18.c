#include<stdio.h>
void order(int a[],int n)
{
	int i,t,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			t=*(a+j);
			*(a+j)=*(a+j+1);
			*(a+j+1)=t;
		}
	}
	printf("排序后的数组\n");
	for(i=0;i<n;i++)
	{
		if(i%5==0)
		{
			printf("\n");
		}
		printf("%d",*(a+i));
	}
	printf("\n");
}
void main()
{
	int a[20],i,n;
	int *p;
	p=a;
	printf("请输入数组元素的个数\n");
	scanf("%d",&n);
	printf("请输入各个元素\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",p++);
	}
	p=a;
	order(p,n);
}