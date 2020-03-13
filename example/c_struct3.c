#include<stdio.h>
struct Student
{
	char cName[20];
	int iNumber;
	char cSex;
	int iGeade;
} student[5] = 
{
	{"WangJuasheng",12062212,'M',3},
	{"YuLongjiao",12062213,'W',3},
	{"JiangXuehuan",12062214,'W',3},
	{"ZhangMeng",12062215,'W',3},
	{"HanLiang",12062216,'M',3}
};

int main()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("NO%d student:\n", i+1);
		printf("Name: %s,Number: %d\n",student[i].cName,student[i].iNumber);
		printf("Sex: %c,Grade: %d\n",student[i].cSex,student[i].iGeade);
		printf("\n");
	}
	return 0;
}