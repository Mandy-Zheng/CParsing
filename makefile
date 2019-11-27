ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: parsing.o
	$(CC) -o program parsing.o

parsing.o: parsing.c
	$(CC) -c parsing.c

run:
	./program

clean:
	rm *.o
	rm *.exe

memcheck:
	valgrind --leak-check=yes ./program
