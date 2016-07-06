.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=fileno 01open 02open 03open 04lseek 05hole
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
