/* 
Karathanasis Dimitris
Askisi 2
myString.h 
*/


#include <stdio.h>
#include <assert.h>
#include <stddef.h>


/* Calculate the lenght of a string
  Check if c is NULL */
size_t ms_length(const char *c);


/* Copy a string  
  Check if parameter src is NULL */
char *ms_copy(char *dest, const char *src);


/* Copy a string  
  Check if parameter src is NULL */
char *ms_ncopy(char *dest, const char *src, size_t n);

  
/* Concatenate two strings 
   Check if parameters dest,src are NULL */
char *ms_concat(char *dest, const char *src);


/* Concatenate two strings 
   Check if parameters dest,src  are NULL */
char *ms_nconcat(char *dest, const char *src, size_t n);


/* Compare two strings 
   Check if parameters s1,s2 are NULL */
int ms_compare(const char *s1, const char *s2);


/* Compare two strings 
   Check if parameters s1,s2 are NULL */
int ms_ncompare(const char *s1, const char *s2, size_t n);


/* Locate a substring 
   Check if parameters haystack,needle are NULL */
char *ms_search(const char *haystack, const char *needle);


