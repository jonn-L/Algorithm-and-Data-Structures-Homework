CC = g++
CFLAGS = -Wall -std=c++11
OBJS = HashTable.o
HEADERS = HashTable.hpp

all: main

main: main.cpp $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) main.cpp $(OBJS) -o main

HashTable.o: HashTable.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c HashTable.cpp -o HashTable.o

clean:
	rm -f main $(OBJS)

