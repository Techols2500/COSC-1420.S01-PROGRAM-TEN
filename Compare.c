#include <string.h>

#include "Compare.h"

/*
the void * in the declaration below means that we have to change it
to the correct pointer type inside the function
*/

int CompareNames(const void * pParam1, const void * pParam2)
{
	const char * pName1 = *(const char **)pParam1;
	const char * pName2 = *(const char **)pParam2;

	return strcmp(pName1, pName2);
}