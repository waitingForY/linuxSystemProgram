.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=produce_consume

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
produce_consume:produce_consume.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread -lrt
clean:
	rm -f *.o $(BIN)
