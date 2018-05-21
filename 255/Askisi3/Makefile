list: symtablelist.o testsymtab.o
	gcc -ansi -pedantic -Wall -o testsymtab_list symtablelist.o testsymtab.o

hash: symtablehash.o testsymtab.o
	gcc -ansi -pedantic -Wall -o testsymtab_hash symtablehash.o testsymtab.o

testsymtab.o: testsymtab.c symtable.h
	gcc -ansi -pedantic -Wall -c testsymtab.c

symtablelist.o: symtablelist.c symtable.h
	gcc -ansi -pedantic -Wall -c symtablelist.c

symtablehash.o: symtablehash.c symtable.h
	gcc -ansi -pedantic -Wall -c symtablehash.c

clean:
	rm -f *.o testsymtab_hash testsymtab_list


