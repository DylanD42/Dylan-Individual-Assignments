CC = g++
TARGET = run
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): bst.o driver.o
	$(CC) -g -Wall -Wextra -o $(TARGET) driver.o bst.o

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) bst.cpp

driver.o: driver.cpp bst.h
	$(CC) $(CFLAGS) driver.cpp

clean:
	$(RM) $(TARGET) *.o *~
