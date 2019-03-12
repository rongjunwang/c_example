#include<stdio.h>
int main()
{
	struct Student
	{
		char cName[20];
		int iNumber;
		char cSex;
		int iGrade;
	}student={"SuYuQun",12061212,'W',2};

	struct Student *pStruct;
	pStruct=&student;
	printf("----the student's information----\n");
	printf("Name: %s\n", (*pStruct).cName);
	printf("Number: %d\n", (*pStruct).iNumber);
	printf("Sex: %c\n", (*pStruct).cSex);
	printf("Grade: %d\n", (*pStruct).iGrade);
	return 0;
}