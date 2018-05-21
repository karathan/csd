/*
Karathanasis Dimitris
Askisi 2
myString_arr.c
*/


#include "mystring.h"

/*Calculate the lenght of a string
  Check if c is NULL */

size_t ms_length(const char c[])
{
  size_t uiLenght = 0U;
  assert(c);
  while (c[uiLenght])
  {
    uiLenght++;
  }
  return uiLenght;
}


/*Copy a string
   Check if parameter src is NULL */

char *ms_copy(char dest[], const char src[])
{ /*prepei na checkarw kai to dest kathe fora?? assert */
  size_t i = 0U;
  assert(src);
  while ((dest[i] = src[i]) != '\0')
  {
    i++;
  }
  return dest;
}


/*Copy a string
   Check if parameter src is NULL */

char *ms_ncopy(char dest[], const char src[], size_t n)
{
  size_t i;
  assert(src);
  for (i = 0; i < n && src[i] != '\0'; i++)
  {
    dest[i] = src[i];
  }
  for ( ; i < n; i++)
  {
    dest[i] = '\0';
  }
  return dest;
}


/* Concatenate two strings
   Check if parameter src is NULL */
char *ms_concat(char dest[], const char src[])
{
  size_t i, j;
  assert(src);
  for (i = 0; dest[i] != '\0'; i++);
  for (j = 0; src[j] != '\0'; j++)
  {
    dest[i + j] = src[j];
  }
  dest[i + j] = '\0';
  return dest;
}


/* Concatenate two strings
   Check if parameter src is NULL */
char *ms_nconcat(char dest[], const char src[], size_t n)
{
  size_t i;
  size_t j = ms_length(dest);
  assert(src);
  for (i = 0 ; i < n && src[i] != '\0' ; i++)
  {
    dest[j + i] = src[i];
  }
  dest[j + i] = '\0';
  return dest;
}


/* Compare two strings
   Check if parameters s1,s2 are NULL */

int ms_compare (const char s1[], const char s2[])
{
  size_t i = 0U;
  assert(s1);
  assert(s2);
  while (s1[i] == s2[i])
  {
    if (s1[i] == '\0')
    {
      return 0;
    }
    i++;
  }
  if (s1[i] < s2[i])
  {
    return -1;
  }
  else
  {
    return 1;
  } 
}

/* Compare two strings
   Check if parameters s1,s2 are NULL */

int ms_ncompare (const char s1[], const char s2[], size_t n)
{
  size_t i = 0U;
  assert(s1);
  assert(s2);
  while (i < n && s1[i] == s2[i])
  {
    if (s1[i] == '\0')
    {
      return 0;
    }
    i++;
  }
  while (i < n)
  {
    if (s1[i] < s2[i])
    {
      return -1;
    }
    if (s1[i] > s2[i])
    {
      return 1;
    }
  }
  return 0;
}
