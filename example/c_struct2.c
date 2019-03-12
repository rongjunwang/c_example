#include<stdio.h>
struct Student
{
	char cName[20];
	char cSex;
	int iGrade;
} student1={"HanXue",'W',3};
int main()
{
	struct Student student2={"WangJiasheng",'M',3};

	//输出student1
	printf("the student1's information\n");
	printf("Name: %s\n", student1.cName);
	printf("Sex: %c\n", student1.cSex);
	printf("Grade: %d\n", student1.iGrade);

	//输出student2
	printf("the student2's information\n");
	printf("Name: %s\n", student2.cName);
	printf("Sex: %c\n", student2.cSex);
	printf("Grade: %d\n", student2.iGrade);
	return 0;
}