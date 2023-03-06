CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11

all: sort plot

sort: selectionSort.cpp
	$(CC) $(CFLAGS) -o sort selectionSort.cpp

plot:
	python3 computationTimes.py

clean:
	rm -f cc