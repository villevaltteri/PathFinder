CC = g++
CFLAGS = -I./include -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_FILES = $(wildcard ./src/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

TARGET = app

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

./src/%.o: ./src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)
