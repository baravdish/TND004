# Makefil om man vill köra med MinGW via kommandotolken.

CXX = g++
CFLAGS = -g -Wall
CXXFLAGS := -std=c++11 -std=gnu++11
TARGET = main

all: $(TARGET)

$(TARGET):$(TARGET).cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)