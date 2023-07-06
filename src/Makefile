CXX=g++
MKDIR=mkdir -p
RM=rm -rf
GDB=gdb


CXXFLAGS=-std=c++14 -O2 -Wall
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

BUILD_DIR=build
OBJECTS=source.o igra.o grafika.o lpoteza.o
OBJECT_FILES=$(patsubst %,$(BUILD_DIR)/%,$(OBJECTS))

BINARY=sokoban.out

.PHONY: all run debug clean

all: compile

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BINARY): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(OBJECT_FILES) -o $@ $(LDFLAGS)

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
