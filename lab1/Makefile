CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o

string_driver: main.o my_string.o
	$(CC) $(CFLAGS) -o string_driver main.o my_string.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
my_string.o: my_string.h my_string.c
	$(CC) $(CFLAGS) -c my_string.c
clean:
	rm string_driver main.o my_string.o
