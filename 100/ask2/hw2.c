#include <stdio.h>


int main ()	{
	int parentheses = 0, brackets = 0, braces = 0;
	int par1 = 0, par2 = 0, brk1 = 0, brk2 = 0, brc1 = 0, brc2 = 0, par = 0, brk = 0, brc = 0, a, b;
	int column = 0, line = 1;
	char c;
	
		while (( c = getchar()) != EOF)	{
			column++;
			
			if (c=='(' )	{
			par1++;
			a=line;
			b=column;
			}
			
			if (c==')' )	{
			par2++;
			a=line;
			b=column;
			}
			
			if (c=='[' )	{
			brk1++;
			a=line;
			b=column;
			}
			if (c==']' )	{
			brk2++;
			a=line;
			b=column;
			}
			if (c=='{' )	{
			brc1++;
			a=line;
			b=column;
			}
			if (c=='}' )	{
			brc2++;
			a=line;
			b=column;
			}
			if (c=='\n')	{
			line++;
			column=0;
			}
			}
			par = (par2 - par1);
			brc = (brc2 - brc1);
			brk = (brk2 - brk1);
			if ((-par!=0 && -brk!=0) || (-par!=0 && -brc!=0) || (-brk!=0 && -brc!=0))	{
			printf ( "End-of-file (EOF) reached while:\n%d parentheses,\n%d brackets,\nand %d braces are still open.\n",-par,-brk,-brc);
			return 0;
			}
			if ((par==1 && brk==0 && brc==0) || (par==0 && brk==1 && brc==0) || (par==0 && brk==0 && brc==1))
			if (par==1)	{
			printf ( "Found closing parenthesis at line %d, column %d, but no parenthesis is open.\n",a,b);
			return 0;
			}
			else if (brk==1)	{
			printf ( "Found closing bracket at line %d, column %d, but no bracket is open.\n",a,b);
			return 0;
			}
			else if (brc==1)	{
			printf ( "Found closing brace at line %d, column %d, but no brace is open.\n",a,b);
			return 0;
			}
			
			if (par==0 && brk==0 && brc==0){
			return 0;
			}
}
        