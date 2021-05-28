1: all

all: main.o dzialania.o
	gcc main.o dzialania.o -o kalkus -lm

3: main.o
	gcc main.c -lm

4: dzialania.o
	gcc dzialania.h dzialania.c -lm

clean:
	rm -rf *o *.gch kalkus
