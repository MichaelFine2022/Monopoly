CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Finds all .cpp files recursively based on your directory structure
SOURCES = $(wildcard *.cpp) $(wildcard Tiles/*.cpp) $(wildcard Tiles/Ownable/*.cpp) $(wildcard Tiles/Ownable/Property/*.cpp) $(wildcard Tiles/Drawable/*.cpp) $(wildcard Decks/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = Monopoly.exe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)