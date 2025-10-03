CC = gcc
CFLAGS = -Wall -g
LIBS = -lm
OBJS = main.o node.o operations.o tree.o memory.o

all: brain

brain: $(OBJS)
	$(CC) $(OBJS) -o brain $(LIBS)

main.o: main.c node.h tree.h memory.h
	$(CC) -c main.c $(CFLAGS)

node.o: node.c node.h
	$(CC) -c node.c $(CFLAGS)

operations.o: operations.c operations.h memory.h node.h
	$(CC) -c operations.c $(CFLAGS)

tree.o: tree.c tree.h node.h operations.h
	$(CC) -c tree.c $(CFLAGS)

memory.o: memory.c memory.h
	$(CC) -c memory.c $(CFLAGS)

clean:
	rm -f *.o brain

run: brain
	./brain
