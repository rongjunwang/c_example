/*
* 当定义一个一维数组，数组的名称就是数组在内存中的首地址，
* 1.b 等同于 &b[0]
* 2.*(a+i) 等同于 *(p+i)
* 注意：%5d 输出10进制的数字
*/
#include<stdio.h>
int main()
{
	int *p,*q,a[5],b[5],i;
	p = &a[0];
	q = b;
	printf("please input array a:\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d",&a[i]);
	}
	//输入数组
	printf("please input array b:\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d",&b[i]);
	}
	//输出a
	printf("array a is:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*(p+i));
	}

	printf("array point a:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*(a+i));
	}

	printf("array point1 a:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*p++);
	}

	//输出b
	printf("array b is:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*(q+i));
	}

	printf("array point b is :\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*(b+i));
	}

	printf("array point1 b is:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d\n",*q++);
	}

	return 0;
}