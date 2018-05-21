CC = gcc
FLAGS = -Wall -ansi -pedantic
	
	EXE = ./
	REM = rm -f

all: data3 data6 data9

data3: createdata3.o
	$(CC) $(FLAGS) -o createdata3 createdata3.o
	$(EXE)createdata3 > data3
	
data6: createdata6.o
	$(CC) $(FLAGS) -o createdata6 createdata6.o	
	$(EXE)createdata6 > data6
	
data9: createdata9.o
	$(CC) $(FLAGS) -o createdata9 createdata9.o	
	$(EXE)createdata9 > data9
	
createdata3.o: createdata3.c
	$(CC) $(FLAGS) -c createdata3.c
	
createdata6.o: createdata6.c
	$(CC) $(FLAGS) -c createdata6.c
	
createdata9.o: createdata9.c
	$(CC) $(FLAGS) -c createdata9.c

clean:
	$(REM) *.o createdata3 createdata6 createdata9 data3 data6 data9
