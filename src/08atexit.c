#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

void exit1(void)
{
	printf("this is exit1\n");
}

void exit2(void)
{
	printf("this is exit2\n");
}

int main(void)
{
	//printf("hello i am wjb!");
	atexit(exit1);
	atexit(exit2);
	_exit(0);
}
