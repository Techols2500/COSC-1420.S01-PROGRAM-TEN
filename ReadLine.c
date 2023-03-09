#include <malloc.h>
#include <stdio.h>
#include <string.h> 

#define FIRST_GUESS		50

char * ReadLine()
{
	char	c;
	int		CurrSize;
	int		NumCharsInLine;
	char *	pLine;

	NumCharsInLine = 0;
	CurrSize = FIRST_GUESS;
	pLine = (char *)malloc((CurrSize + 1) * sizeof(char));
	while ((c = getc(stdin)) != '\n')
	{
		pLine[NumCharsInLine++] = c;
		if (NumCharsInLine >= CurrSize)
		{		/* need a bigger array */
			CurrSize += FIRST_GUESS;
			pLine = (char *)realloc(pLine, (CurrSize + 1) * sizeof(char)); /* dynamically change the size of the array */
		}
		else;
	}
	pLine[NumCharsInLine] = '\0';
	if (NumCharsInLine == 0)
	{
		return NULL;
	}
	else 
	return pLine;
}