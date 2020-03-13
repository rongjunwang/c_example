#include<stdio.h>
int main()
{
	char string[] = "abchjk";
	char *p;
	p = &string[1];
	printf("the result1 is: %c\n",*p);
	p+=1;
	printf("the result2 is: %c\n",*p);
}