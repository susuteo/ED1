CC = gcc
CFLAGS = -Wall -g
TARGET = dicionario

all: $(TARGET)

$(TARGET): dicionario.c
	$(CC) $(CFLAGS) -o $(TARGET) dicionario.c

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

