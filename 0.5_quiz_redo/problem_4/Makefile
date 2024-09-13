CC = g++
CFLAGS = -g -Wall -Wextra

defualt: circle

circle:	circle.o main.o
	$(CC) $(Cflags) -o program3 circle.o main.o

circle.o:	circle.cpp circle.h
	$(CC) $(CFLAGS) -c circle.cpp

main.o:		main.cpp circle.h
	$(CC) $(CFLAGS) -c main.cpp
clean:
	$(RM) program3 *.o *~
