.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01sigaction 02mysignal 03sigaction 04signal_recv 04signal_send 05signal_recv 05signal_send

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
