.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01open 02cpfile 03stat 04lstat
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
