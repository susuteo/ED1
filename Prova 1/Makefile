CC = gcc
CFLAGS = -Wall
OBJ = main.o lista.o
TARGET = calculadora

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
