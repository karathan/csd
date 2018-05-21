/*
Karathanasis Dimitris
Askisi 2
myString_arr.c
*/

#include "mystring.h"


/*Calculate the lenght of a string
  Check if c is NULL */
size_t ms_length(const char *c)
{
	const char *cEnd = c;
	assert(c);
	while (*cEnd)
		cEnd++;
	return cEnd - c;
}

/*Copy a string
   Check if parameter src is NULL */
char *ms_copy(char *dest, const char *src)
{
	char *d = dest;
	const char *s = src;
	assert(src);
	while ((*d++ = *s++) != '\0');
	return dest;
}

/*Copy a string
   Check if parameter src is NULL */
char *ms_ncopy(char *dest, const char *src, size_t n)
{
	int i;
	char *temp;
	temp = dest;
	for (i = 0; i < n; i++)
		*dest++ = *src++;
	return temp;
}

/* Concatenate two strings
   Check if parameters dest,src are NULL */
char *ms_concat(char *dest, const char *src)
{
	char *a = dest;
    assert(src != NULL && dest != NULL);
    while (*a != '\0')
    	a++;  
    ms_copy(a, src);
    return dest;
}

/* Concatenate two strings
   Check if parameters dest,src are NULL */
char *ms_nconcat(char *dest, const char *src, size_t n)
{
	char *a = dest;
    assert(src != NULL && dest != NULL);
    while (*a != '\0')
    	a++;
    ms_ncopy(a, src, n);
    return dest;
}

/* Compare two strings 
   Check if parameters s1,s2 are NULL */
int ms_compare(const char *s1, const char *s2)
{
	const char *a = s1;
    const char *s = s2;
	assert(s1 != NULL && s2 != NULL);   
    while (*a != '\0' || *s != '\0')
     {
        if(*a < *s)
        	return -1;
        if(*a > *s)
        	return 1;
        a++;
        s++;
 }
    return 0;
}

/* Compare two strings 
   Check if parameters s1,s2 are NULL */
int ms_ncompare(const char *s1, const char *s2, size_t n)
{
	const char *p = s1;
    const char *q = s2;
    size_t i = 0U;
	assert(s1 != NULL && s2 != NULL);
    while (i++ < n && (*p != '\0' || *q != '\0'))
     {
          if(*p < *q)
          	return -1;
          if(*p > *q)
          	return 1;
          p++;
          q++;
     }
    return 0;
}

/* Locate a substring 
   Check if parameters haystack,needle are NULL */
char *ms_search(const char *haystack, const char *needle)
{
	const char *ptr1 = haystack;
    const char *ptr2 = needle;
    size_t n = ms_length(needle);
    assert(haystack != NULL && needle != NULL);
    while ( *ptr1 != '\0')
     {
        if(ms_ncompare(ptr1, ptr2, n) == 0)
            return (char *)ptr1;
        ptr1++;
     }
    return NULL; 
}