#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(void)
{
	int fp;
	/*
	if((fp=open("test.txt",O_RDONLY))<0)
	  ERR_EXIT("open file:");
	*/
	if((fp=open("test.txt",O_WRONLY|O_CREAT|O_EXCL,0644))<0)
	  ERR_EXIT("open file:");
	printf("open success\n");
	return 0;
}
