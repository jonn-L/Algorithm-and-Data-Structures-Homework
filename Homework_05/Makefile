CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11

all: fib plot

fib: fibonacci.cpp
	$(CC) $(CFLAGS) -o fib fibonacci.cpp
	./fib

plot: fib
	python3 computationTimes.py

clean:
	rm -f fib



