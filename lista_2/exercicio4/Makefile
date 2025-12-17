CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

SRC = $(wildcard src/*.cpp)
TARGET = ex4

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) src/*.o
