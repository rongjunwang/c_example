#include<stdio.h>
struct Product
{
	char cName[10];		//产品名称
	char cShape[20];	//形状
	char cColor[10];	//颜色
	int iPrice;			//价格
	char cArea[20];		//产地
};
int main()
{
	struct Product product1;
	printf("please enter product's name\n");
	scanf("%s",product1.cName);
	printf("please enter product's shape\n");
	scanf("%s",product1.cShape);
	printf("please enter product's color\n");
	scanf("%s",product1.cColor);
	printf("please enter product's price\n");
	scanf("%d",&product1.iPrice);
	printf("please enter product's area\n");
	scanf("%s",product1.cArea);

	printf("Name: %s\n", product1.cName);
	printf("Shape: %s\n", product1.cShape);
	printf("Color: %s\n", product1.cColor);
	printf("Price: %d\n", product1.iPrice);
	printf("Area: %s\n", product1.cArea);

	return 0;
}