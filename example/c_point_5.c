/*
* int存储连续地址，可以通过地址加一，指向下一个变量
*/
#include<stdio.h>
int main()
{
	int number[4] = {1,2,3,4};
	int *p;
	p = &number[1];
	printf("the number1 is: %d\n",*p);			//输出2
	p+=1;
	printf("the number2 is: %d\n",*p);			//输出3
}