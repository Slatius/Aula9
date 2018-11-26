CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -g
PROGRAM=wordcount

$(PROGRAM): main.o wcfuncs.o
	$(CC) main.o wcfuncs.o -o $(PROGRAM)

main.o: main.c wcfuncs.h
	$(CC) $(CFLAGS) -c -o main.o main.c

wcfuncs.o: wcfuncs.c wcfuncs.h
	$(CC) $(CFLAGS) -c -o wcfuncs.o wcfuncs.c

clean:
	rm -f $(PROGRAM) *.o

