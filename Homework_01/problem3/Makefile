CC = g++
CFLAGS = -Wall -O2
TARGET = problem3

$(TARGET): LinkedList.h testLinkedList.cpp
	$(CC) $(CFLAGS) -o $(TARGET) LinkedList.h testLinkedList.cpp

clean:
	rm -f $(TARGET)