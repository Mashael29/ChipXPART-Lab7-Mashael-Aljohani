#include<stdio.h>
#include<ctype.h>
int main()
{
	char String;
	int characters=0;
	int words=0;
	int lines=0;
	int inWord;

	FILE *MyFile = fopen("cx-202-lab7/task2test.txt","r");
	if (MyFile==NULL)
	{
		printf("Error opening the file\n");
		return 1;
	}
        
	while((String=fgetc(MyFile))!=EOF)
	{
		characters++;

	if(String=='\n' || String=='\0')
	{
		lines++;
	}

	if(isspace(String))
	{
		if(inWord)
		{
			words++;
			inWord=0;
		}
	}
	else 
	{
		inWord=1;
	}
	}

	if(inWord)
	{
		words++;
	}

	fclose(MyFile);
	
	printf("The number of words in the file is : %d\n",words);
	printf("The number of characters in the file is %d\n",characters);
	printf("The number of lines in the file is %d\n",lines);

	return 0;

}

