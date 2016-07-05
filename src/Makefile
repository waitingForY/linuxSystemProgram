.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01open 02cpfile 03stat 04lstat 05fork 06fork 07exit 08atexit \
	09forkwithfile
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
