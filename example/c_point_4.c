#include<stdio.h>
int main()
{
	int i;
	int *p;
	printf("please input the number\n");
	scanf("%d",&i);
	p = &i;
	printf("the result1 point is : %p\n",p);
	printf("the result1 is : %d\n",*p);
	//地址加一
	p++;					
	printf("the result2 point is : %p\n",p);
	printf("the result2 is : %d\n",*p);
	return 0;
}