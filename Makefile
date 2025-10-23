CC=g++
CFLAGS=-c -Wall
all: task1 task2

task1: task1.o
	$(CC) task1.o -o task1
	rm -rf *.o
	
task2: task2.o
	$(CC) task2.o -o task2
	rm -rf *.o

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm task1
	rm task2