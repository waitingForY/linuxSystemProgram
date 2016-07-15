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
	int outfd;
	outfd=open("Makefile2",O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(outfd==-1)
	  ERR_EXIT("open Makefile error");
	int fifofd;
	fifofd=open("tp",O_RDONLY);
	if(fifofd==-1)
	  ERR_EXIT("open tp error");
	char buf[1024]={0};
	int nread;
	while((nread=read(fifofd,buf,1024))>0)
	{
		write(outfd,buf,nread);
	}
	close(outfd);
	close(fifofd);
	unlink("tp");
	return 0;
}
