CC=gcc
CFLAGS=-Wall

all: main

main: main.o ponto.o
	$(CC) $(CFLAGS) -o main main.o ponto.o -lm

main.o: main.c ponto.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

run: main
	./main

clean:
	rm -f *.o main
