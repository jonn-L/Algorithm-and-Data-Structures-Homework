CC = g++
CFLAGS = -Wall -O2
TARGET = problem2

$(TARGET): Stack.h testStack.cpp
	$(CC) $(CFLAGS) -o $(TARGET) Stack.h testStack.cpp

clean:
	rm -f $(TARGET)
