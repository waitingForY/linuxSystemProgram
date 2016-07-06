.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=fileno 01open 02open 03open 04lseek 05hole 06my_ls 07stat 08fileshare
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
