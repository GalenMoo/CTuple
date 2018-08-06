#makefile for tuple

CC = gcc
CFLAGS = -Wall
TEST = tupletest
LIB = tuple
SRC = $(TEST).c
HDRS = $(LIB).h

test:
	make all
	./$(TEST)
	make clean

all: $(TEST) 

$(TEST): $(SRC)
	$(CC) $(CFLAGS) -o $(TEST) $(SRC)

clean:
	-rm $(TEST) *.o