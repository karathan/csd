/* Karathanasis Dimitris 3547
Ask3
testsymtab.c */


#include "symtable.h"

void map_test(const char *pcKey, void *pvValue, void *pvExtra)
{
    *(char *)pvValue = *(char*) pvExtra;
}

int main()
{
	char s1[] = "abc", s2[] = "def", s3[] = "ghi", s4[] = "xyz";
	char *s5 = s4;
	int i,j;
	SymTable_T oSymTable = NULL;
	oSymTable = SymTable_new();
    i = SymTable_put(oSymTable, s1, (char *)s2);			/*Symtable_put test */
    j = SymTable_put(oSymTable, s2, (char *)s3);
    if (i == 1)																	
	{
		printf("Element with key=s1 and value=s2 added successfully\n");
	}
	if (j == 1)
	{
		printf("Element with key=s2 and value=s3 added successfully\n");
	}	
	printf("length = %d\n",SymTable_getLength(oSymTable));					/*Symtable get_lenght test */
	printf("get this: %s\n", (char *)SymTable_get(oSymTable, s2));			 /* SymTable_get test */

	/* SymTable_remove and SymTable_contains test */
    SymTable_remove(oSymTable, s1);
    if (SymTable_contains(oSymTable, s1) == 0) printf("Element with key=s1 removed successfully\n");
	printf("NEWlength = %d\n",SymTable_getLength(oSymTable));					 /* Length updated */
    SymTable_free(oSymTable);												 
	return 0;
}
