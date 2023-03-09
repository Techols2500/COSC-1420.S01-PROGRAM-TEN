/*
DESCRIPTION: Programming Excerise Ten
CLASS: COSC 1420.SO1
AUTHOR: TYLER ECHOLS
DATE: April 2019
*/
#pragma warning (disable:4996)

#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Compare.h"
#include "ReadLine.h"
#include <search.h>

int main()
{
	BOOL		Complete;
	char **		Name;
	char *		pNames;
	char *		a;
	int			q = 0;
	int			b;
	BOOL		c = TRUE;
	int			Found;

	Name = (char**)malloc(20 * sizeof(char*));
	do {
		printf("Enter names: press the enter key to stop listing \n");
		Name[q] = ReadLine();



		
		if (Name[q] != NULL)
		{
			q++;
			Complete = 0;
		}
		else
			Complete = 1;

		if (q >= 20)
		{
			Name = (char**)realloc(Name, 20 * sizeof(char*));
		}

	} while (!Complete);

	
	for (b = 0; b < q; b++)
		printf("\n Inserted Name [%d] is %s \n " ,b, Name[b]);

	qsort(Name, q, sizeof(char*), CompareNames);
	
	printf("\n\n");

	for (b = 0; b < q; b++)
		printf("\n The index [%d] now hold the name %s \n", b, Name[b]);
	do {
		printf("\n Type in name to locate index if not press enter to close: \n");
		pNames = ReadLine();
		if (pNames == NULL)
			c = FALSE;
		else
		{
			c = TRUE;
			a = (char**)bsearch(&pNames, Name, q, sizeof(char*), CompareNames);
			
			if (a == NULL)
			{
				printf("Does not exist \n");

				
			}
			else
			{
				Found = (((unsigned int)a - (unsigned int)Name) / sizeof(char*));
				printf("\n We found that name under index[%d] \n", Found);
			

			}
		}
	} while (c == TRUE);
	for (int b = 0; b < q; b++)
	{
		free(Name[b]);
	}
	
	free(Name);
	printf("\n press enter to close \n");
	_getch();
	return 0;
}