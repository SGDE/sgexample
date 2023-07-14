



CC = gcc

CFLAGS = `pkg-config --cflags gtk+-3.0`

LIBS = `pkg-config --libs gtk+-3.0` -lm

# File names

SRC = example.c

OBJ = $(SRC:.c=.o)

EXE = example

# Build executable files

all: $(EXE)

example: example.o

	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Debug step

debug:

	$(CC) $(CFLAGS) -g $(SRC) -o debug $(LIBS)

# Test step

test:

	./example

# Clean object files and executables

clean:

	rm -f $(OBJ) $(EXE) debug
