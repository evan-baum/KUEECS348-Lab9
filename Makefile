CC=g++
CFLAGS=-c -Wall
all: task1 task2

task1: task1.o
	$(CC) task1.o -o task1
	rm -rf *.o
	
task2: task2.o
	$(CC) task2.o -o task2
	rm -rf *.o

task3: task3.o
	$(CC) task3.o -o task3
	rm -rf *.o

task4: task4.o
	$(CC) task4.o -o task4
	rm -rf *.o

task5: task5.o
	$(CC) task5.o -o task5
	rm -rf *.o

task6: task6.o
	$(CC) task2.6 -o task6
	rm -rf *.o

task7: task7.o
	$(CC) task7.o -o task7
	rm -rf *.o

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm task1
	rm task2