#include<stdio.h>
#include<string.h>

struct Student
{
	int id;
	char name[50];
	float gpa;
};

int main()
{
	int Counter;
	printf("Enter the number of student: ");
	scanf("%d",&Counter);
	 
	struct Student student[Counter];

	for(int i=0;i<Counter;i++)
	{
		printf("Enter ID for student %d: ",i+1);
		scanf("%d",&student[i].id);
		printf("Enter name for the student %d: ",i+1);
		scanf(" %[^\n]",student[i].name);
		printf("Enter the GPA for the student %d : ",i+1);
		scanf("%f",&student[i].gpa);

	}
	
	for(int i=0;i<Counter;i++)
	{	
	printf("ID: %d, Name: %s, GPA: %.2f\n",student[i].id,student[i].name,student[i].gpa);
	}
	printf("\n");
	return 0;
}
