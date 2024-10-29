CC = g++
TARGET = test
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): phonebook.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o phonebook.o

phonebook.o: phonebook.cpp phonebook.h
	$(CC) $(CFLAGS) phonebook.cpp

main.o: main.cpp phonebook.h
	$(CC) $(CLFAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
