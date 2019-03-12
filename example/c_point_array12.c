/*
* 这个例子主要跟上一次例子做对比，传值和传地址（即 指针）的区别
*/
#include<stdio.h>
void swap(int a,int b);
int main()
{
	int x,y;
	printf("please input:\n");
	scanf("%d",&x);
	scanf("%d",&y);
	swap(x,y);
	printf("x=%d\n",x);
	printf("y=%d\n",y);
	return 0;
}
void swap(int a,int b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}