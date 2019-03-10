#include<stdio.h>
int main(){
	int a[3][5],i,j,*p;
	p=a[0];
	printf("please input\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",p++);
		}
	}
	p=a[0];
	printf("the array is:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%5d\n",*p++);
		}
		printf("\n");
	}
	return 0;
}