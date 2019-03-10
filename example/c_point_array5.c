#include<stdio.h>
int main()
{
	int a[3][5],i,j;
	printf("please input:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%5d",*(a+i)+j);
		}
	}
	printf("the second line is :\n");
	for(j=0;j<5;j++)
	{
		printf("%5d",*(*(a+1)+j));
	}
	printf("\n");
	return 0;
}