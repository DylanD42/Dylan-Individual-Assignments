CC = g++
TARGET = book
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): Phonebook.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o Phonebook.o

Phonebook.o: Phonebook.cpp Phonebook.h
	$(CC) $(CFLAGS) Phonebook.cpp

main.o: main.cpp Phonebook.h
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
