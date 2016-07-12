.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01sigaction 02mysignal 03sigaction

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
