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
	if(mkfifo("tp",0644)==-1)
	  ERR_EXIT("mkfifo error");
	int infd;
	infd=open("Makefile",O_RDONLY);
	if(infd==-1)
	  ERR_EXIT("open Makefile error");
	int fifofd;
	fifofd=open("tp",O_WRONLY);
	if(fifofd==-1)
	  ERR_EXIT("open tp error");
	char buf[1024]={0};
	int nread;
	while((nread=read(infd,buf,1024))>0)
	{
		write(fifofd,buf,nread);
	}
	close(infd);
	close(fifofd);
	return 0;
}
