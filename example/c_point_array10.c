#include<stdio.h>
int main()
{
	int a[10],*p1,**p2,n=0;
	printf("please input:\n");
	for(p1=a;p1-a<10;p1++)
	{
		p2=&p1;
		scanf("%d",*p2);
	}
	printf("the array is:\n");
	for(p1=a;p1-a<10;p1++)
	{
		p2=&p1;
		if(**p2%2 == 0)
		{
			printf("%5d\n",**p2);
			n++;
		}
	}
	printf("\n");
	printf("the number is:%d\n",n);
	return 0;
}