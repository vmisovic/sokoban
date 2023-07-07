SRC_DIR=src
BUILD_DIR=build
BINARY=sokoban.out

CXX=g++
GDB=gdb
MKDIR=mkdir -p
RM=rm -rf

CXXFLAGS=-std=c++14 -O2 -Wall
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

.PHONY: all run debug clean

all: compile

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

compile:
	$(MKDIR) $(BUILD_DIR)
	$(MAKE) $(BINARY)

run: compile
	./$(BINARY)

debug: $(BINARY)
	$(GDB) $(BINARY)

clean:
	$(RM) $(BUILD_DIR) $(BINARY)

-include $(OBJECT_FILES:.o=.d)
