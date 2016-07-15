#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0);

int main(void)
{
	/*
	if(mkfifo("tp",0644)==-1)
	  ERR_EXIT("mkfifo error");
	*/
	int fifop;
	fifop=open("tp",O_WRONLY | O_NONBLOCK);
	if(fifop==-1)
	  ERR_EXIT("open tp error");
	printf("open tp success\n");
	return 0;
}
