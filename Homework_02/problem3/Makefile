CC = g++
CFLAGS = -Wall -O2
TARGET = problem3

$(TARGET): WindGauge.h WindGauge.cpp testWindGauge.cpp
	$(CC) $(CFLAGS) -o $(TARGET) WindGauge.h WindGauge.cpp testWindGauge.cpp

clean:
	rm -f $(TARGET)