CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11

all: sort plot

sort: merge_insertion_sort.cpp
	$(CC) $(CFLAGS) -o sort merge_insertion_sort.cpp

plot:
	python3 computationTimes.py

clean:
	rm -f cc