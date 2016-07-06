.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01setsid 02daemon 03my_daemon
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
