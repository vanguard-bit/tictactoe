CC=gcc
CFLAGS=-Wall -Wextra -Iinclude
LDFLAGS=-lncursesw

SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=build/%.o)

TARGET=build/tictactoe

all: $(TARGET)

# Link step
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile step
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build/ exists
build:
	mkdir -p build

clean:
	rm -rf build

