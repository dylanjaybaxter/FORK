CC = gcc
CFLAGS = -Wall -g
LD = gcc
LDFLAGS = -g

all: tryit forkit

tryit: tryit.o
	$(CC) $(CFLAGS) -o tryit tryit.o

tryit.o: tryit.c
	$(CC) $(CFLAGS)  -c -o tryit.o tryit.c

forkit: forkit.o
	$(CC) $(CFLAGS) -o forkit forkit.o

forkit.o: forkit.c
	$(CC) $(CFLAGS)  -c -o forkit.o forkit.c

clean: tryit forkit
	rm tryit.o forkit.o