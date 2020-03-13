#include<stdio.h>
int main()
{
	int a[3][5],i,j,(*p)[5];
	p=&a[0];
	printf("please input:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",(*(p+i) +j));
		}
	}
	p=&a[2];
	printf("the third line is:\n");
	for(j=0;j<5;j++)
	{
		printf("%5d",*((*p)+j));
	}
	printf("\n");
	return 0;
}