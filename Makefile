CC = gcc
CFLAGS = -Wall

SRC = src/lexer.c src/parser.c src/codegen.c main.c
OBJ = $(SRC:.c=.o)

all: compiler

compiler: $(OBJ)
	$(CC) $(CFLAGS) -o compiler $(OBJ)

clean:
	rm -f $(OBJ) compiler
