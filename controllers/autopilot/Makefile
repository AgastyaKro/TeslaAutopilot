WEBOTS_HOME = /Applications/Webots.app/Contents

CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -std=c++17 -I$(WEBOTS_HOME)/include/controller/cpp
LDFLAGS = -L$(WEBOTS_HOME)/lib/controller -lCppController

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = autopilot

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
