CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o unit_test.o

string_driver: main.o my_string.o status.o
	$(CC) $(CFLAGS) -o string_driver main.o my_string.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
my_string.o: my_string.h my_string.c
	$(CC) $(CFLAGS) -c my_string.c
status.o: status.h
	$(CC) $(CFLAGS) -c status.h
boolean.o: boolean.h
	$(CC) $(CFLAGS) -c boolean.h
unit_test: my_string_o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
unit_test.o: unit_test.h unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c
clean:
	rm string_driver main.o my_string.o status.o test_def.o unit_test.o boolean.o
