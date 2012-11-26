#
# Sample Makefile for lsh
# lab1 in Operating System course
#
BIN=rr_simu

CC=	gcc
CFLAGS= -ggdb 
LIBS= -lpthread 
SRC=round_robin_simulation.c

all:
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(BIN)

clean:
	-rm $(BIN)

run: clean all
	./$(BIN)

