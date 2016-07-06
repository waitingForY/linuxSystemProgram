.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01setsid 02daemon
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
