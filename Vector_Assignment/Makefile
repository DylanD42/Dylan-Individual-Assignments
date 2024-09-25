CC = g++
TARGET = test
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): Vector.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o Vector.o

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) Vector.cpp

main.o: main.cpp Vector.h
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
