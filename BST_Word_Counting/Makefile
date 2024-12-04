CC = g++
TARGET = run
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): bst.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o bst.o

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) bst.cpp

main.o: main.cpp bst.h
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
