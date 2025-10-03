CC=gcc
CFLAGS=-Wall

all: main

main: main.o lista.o
	$(CC) $(CFLAGS) -o main main.o lista.o -lm

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

run: main
	./main

clean:
	rm -f *.o main
