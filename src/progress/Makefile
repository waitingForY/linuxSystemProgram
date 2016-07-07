.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01fork 02fork 03exit 04atexit 05forkwithfile 06vfork 07exec test print_environ 08execle 09my_system
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
