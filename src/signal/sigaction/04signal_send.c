#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

#define ERR_EXIT(m) \
	do{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	}while(0);


int main(int argc,char **argv)
{
	union sigval val;
	if(argc!=2)
	{
		printf("Usage:%s signumber\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	val.sival_int=100;
	pid_t pid=atoi(argv[1]);
	if(sigqueue(pid,SIGINT,val)<0)
	  ERR_EXIT("sigqueue error");
	return 0;
}
